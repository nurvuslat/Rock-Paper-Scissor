#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 2

struct Client {
    int socketFD;
    char nickname[50];
    char move[10];
    bool hasPlayed;
};

struct Client clients[MAX_CLIENTS];
int clientCount = 0;
pthread_mutex_t clientsLock = PTHREAD_MUTEX_INITIALIZER;

void *handleClient(void *arg);
void determineWinnerAndAnnounce();

int main() {
    int serverSocketFD = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(2000);

    if (bind(serverSocketFD, (const struct sockaddr *)&serverAddress, sizeof(serverAddress)) == 0)
        printf("Socket was bound successfully\n");

    listen(serverSocketFD, MAX_CLIENTS);

    while (true) {
        if (clientCount < MAX_CLIENTS) {
            struct sockaddr_in clientAddress;
            socklen_t clientAddressSize = sizeof(clientAddress);
            int clientSocketFD = accept(serverSocketFD, (struct sockaddr *)&clientAddress, &clientAddressSize);

            pthread_mutex_lock(&clientsLock);
            clients[clientCount].socketFD = clientSocketFD;
            clients[clientCount].hasPlayed = false;
            pthread_mutex_unlock(&clientsLock);

            pthread_t threadID;
            pthread_create(&threadID, NULL, handleClient, &clients[clientCount]);

            pthread_mutex_lock(&clientsLock);
            clientCount++;
            pthread_mutex_unlock(&clientsLock);
        }
    }

    shutdown(serverSocketFD, SHUT_RDWR);
    return 0;
}

void *handleClient(void *arg) {
    struct Client *client = (struct Client *)arg;
    char buffer[1024];

    ssize_t amountReceived = recv(client->socketFD, buffer, sizeof(buffer) - 1, 0);
    if (amountReceived > 0) {
        buffer[amountReceived] = '\0'; 
        strncpy(client->nickname, buffer, sizeof(client->nickname));
        client->nickname[sizeof(client->nickname) - 1] = '\0';

       
        snprintf(buffer, sizeof(buffer), "Welcome, %s! Waiting for other players...\n", client->nickname);
        send(client->socketFD, buffer, strlen(buffer), 0);
    }

    while (true) {
     
        amountReceived = recv(client->socketFD, buffer, sizeof(buffer) - 1, 0);
        if (amountReceived > 0) {
            buffer[amountReceived] = '\0';

            pthread_mutex_lock(&clientsLock);
            strncpy(client->move, buffer, sizeof(client->move));
            client->hasPlayed = true;

      
            bool allPlayed = true;
            for (int i = 0; i < clientCount; i++) {
                if (!clients[i].hasPlayed) {
                    allPlayed = false;
                    break;
                }
            }

            if (allPlayed && clientCount == MAX_CLIENTS) {
                determineWinnerAndAnnounce();
                for (int i = 0; i < clientCount; i++) {
                    clients[i].hasPlayed = false; 
                }
            }

            pthread_mutex_unlock(&clientsLock);
        }

        if (amountReceived == 0) {
            close(client->socketFD);
            break;
        }
    }

    return NULL;
}


void determineWinnerAndAnnounce() {
    char *move1 = clients[0].move;
    char *move2 = clients[1].move;
    char result[1024];

    if (strcmp(move1, move2) == 0) {
        snprintf(result, sizeof(result), "Draw! Both chose %s.\n", move1);
    } else if ((strcmp(move1, "rock") == 0 && strcmp(move2, "scissors") == 0) ||
               (strcmp(move1, "scissors") == 0 && strcmp(move2, "paper") == 0) ||
               (strcmp(move1, "paper") == 0 && strcmp(move2, "rock") == 0)) {
        snprintf(result, sizeof(result), "%s wins! %s beats %s.\n", clients[0].nickname, move1, move2);
    } else {
        snprintf(result, sizeof(result), "%s wins! %s beats %s.\n", clients[1].nickname, move2, move1);
    }

    for (int i = 0; i < clientCount; i++) {
        send(clients[i].socketFD, result, strlen(result), 0);
    }
}
