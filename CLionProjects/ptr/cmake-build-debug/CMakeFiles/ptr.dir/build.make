# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/x86/clion-2020.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/x86/clion-2020.1.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lqc/CLionProjects/ptr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lqc/CLionProjects/ptr/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ptr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ptr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ptr.dir/flags.make

CMakeFiles/ptr.dir/main.c.o: CMakeFiles/ptr.dir/flags.make
CMakeFiles/ptr.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lqc/CLionProjects/ptr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ptr.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ptr.dir/main.c.o   -c /home/lqc/CLionProjects/ptr/main.c

CMakeFiles/ptr.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ptr.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lqc/CLionProjects/ptr/main.c > CMakeFiles/ptr.dir/main.c.i

CMakeFiles/ptr.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ptr.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lqc/CLionProjects/ptr/main.c -o CMakeFiles/ptr.dir/main.c.s

# Object files for target ptr
ptr_OBJECTS = \
"CMakeFiles/ptr.dir/main.c.o"

# External object files for target ptr
ptr_EXTERNAL_OBJECTS =

ptr: CMakeFiles/ptr.dir/main.c.o
ptr: CMakeFiles/ptr.dir/build.make
ptr: CMakeFiles/ptr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lqc/CLionProjects/ptr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ptr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ptr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ptr.dir/build: ptr

.PHONY : CMakeFiles/ptr.dir/build

CMakeFiles/ptr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ptr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ptr.dir/clean

CMakeFiles/ptr.dir/depend:
	cd /home/lqc/CLionProjects/ptr/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lqc/CLionProjects/ptr /home/lqc/CLionProjects/ptr /home/lqc/CLionProjects/ptr/cmake-build-debug /home/lqc/CLionProjects/ptr/cmake-build-debug /home/lqc/CLionProjects/ptr/cmake-build-debug/CMakeFiles/ptr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ptr.dir/depend

