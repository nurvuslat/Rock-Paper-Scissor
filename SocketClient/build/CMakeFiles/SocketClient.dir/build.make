# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/deneme/Desktop/TCP_Client_Server_Application-main/SocketClient

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/deneme/Desktop/TCP_Client_Server_Application-main/SocketClient/build

# Include any dependencies generated for this target.
include CMakeFiles/SocketClient.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SocketClient.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SocketClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SocketClient.dir/flags.make

CMakeFiles/SocketClient.dir/main.c.o: CMakeFiles/SocketClient.dir/flags.make
CMakeFiles/SocketClient.dir/main.c.o: /home/deneme/Desktop/TCP_Client_Server_Application-main/SocketClient/main.c
CMakeFiles/SocketClient.dir/main.c.o: CMakeFiles/SocketClient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/deneme/Desktop/TCP_Client_Server_Application-main/SocketClient/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SocketClient.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SocketClient.dir/main.c.o -MF CMakeFiles/SocketClient.dir/main.c.o.d -o CMakeFiles/SocketClient.dir/main.c.o -c /home/deneme/Desktop/TCP_Client_Server_Application-main/SocketClient/main.c

CMakeFiles/SocketClient.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SocketClient.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/deneme/Desktop/TCP_Client_Server_Application-main/SocketClient/main.c > CMakeFiles/SocketClient.dir/main.c.i

CMakeFiles/SocketClient.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SocketClient.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/deneme/Desktop/TCP_Client_Server_Application-main/SocketClient/main.c -o CMakeFiles/SocketClient.dir/main.c.s

# Object files for target SocketClient
SocketClient_OBJECTS = \
"CMakeFiles/SocketClient.dir/main.c.o"

# External object files for target SocketClient
SocketClient_EXTERNAL_OBJECTS =

SocketClient: CMakeFiles/SocketClient.dir/main.c.o
SocketClient: CMakeFiles/SocketClient.dir/build.make
SocketClient: /home/deneme/Desktop/TCP_Client_Server_Application-main/SocketUtil/build/libSocketUtil.a
SocketClient: CMakeFiles/SocketClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/deneme/Desktop/TCP_Client_Server_Application-main/SocketClient/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SocketClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SocketClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SocketClient.dir/build: SocketClient
.PHONY : CMakeFiles/SocketClient.dir/build

CMakeFiles/SocketClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SocketClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SocketClient.dir/clean

CMakeFiles/SocketClient.dir/depend:
	cd /home/deneme/Desktop/TCP_Client_Server_Application-main/SocketClient/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/deneme/Desktop/TCP_Client_Server_Application-main/SocketClient /home/deneme/Desktop/TCP_Client_Server_Application-main/SocketClient /home/deneme/Desktop/TCP_Client_Server_Application-main/SocketClient/build /home/deneme/Desktop/TCP_Client_Server_Application-main/SocketClient/build /home/deneme/Desktop/TCP_Client_Server_Application-main/SocketClient/build/CMakeFiles/SocketClient.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SocketClient.dir/depend

