#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include "socketutil.h"

void startListeningAndPrintMessagesOnNewThread(int fd);

void *listenAndPrint(void *arg);

void readConsoleEntriesAndSendToServer(int socketFD);

int main() {
    int socketFD = createTCPIpv4Socket();
    struct sockaddr_in *address = createIPv4Address("127.0.0.1", 2000);

    int result = connect(socketFD, (struct sockaddr *)address, sizeof(*address));

    if (result == 0)
        printf("Connection was successful\n");

    startListeningAndPrintMessagesOnNewThread(socketFD);

    readConsoleEntriesAndSendToServer(socketFD);

    close(socketFD);

    return 0;
}
void readConsoleEntriesAndSendToServer(int socketFD) {
    char name[50];
    printf("Please enter your name:\n");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; 

    send(socketFD, name, strlen(name), 0);

    char line[1024];
    sleep(1); 

    printf("Hi %s, You can choose between rock, paper, scissors (type 'exit')...\n", name);

    while (true) {
        printf("\n");
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0'; 

        if (strcmp(line, "exit") == 0)
            break;

        send(socketFD, line, strlen(line), 0);
    }
}



void startListeningAndPrintMessagesOnNewThread(int socketFD) {
    pthread_t id;
    int *socketFDPointer = malloc(sizeof(int)); 
    *socketFDPointer = socketFD;               
    pthread_create(&id, NULL, listenAndPrint, socketFDPointer);
}

void *listenAndPrint(void *arg) {
    int socketFD = *((int *)arg); 
    free(arg); 

    char buffer[1024];
    bool firstMessage = true; 

    while (true) {
        ssize_t amountReceived = recv(socketFD, buffer, sizeof(buffer) - 1, 0);

        if (amountReceived > 0) {
            buffer[amountReceived] = '\0'; 

            if (firstMessage) {
                printf("%s\n", buffer); 
                firstMessage = false;
            } else {
                
                printf("Response was: %s\n", buffer);
            }
        }

        if (amountReceived == 0) {
            break; 
        }
    }

    close(socketFD);
    return NULL;
}
