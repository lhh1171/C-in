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
CMAKE_SOURCE_DIR = /home/lqc/CLionProjects/inli

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lqc/CLionProjects/inli/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/inli.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/inli.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/inli.dir/flags.make

CMakeFiles/inli.dir/main.c.o: CMakeFiles/inli.dir/flags.make
CMakeFiles/inli.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lqc/CLionProjects/inli/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/inli.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/inli.dir/main.c.o   -c /home/lqc/CLionProjects/inli/main.c

CMakeFiles/inli.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/inli.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lqc/CLionProjects/inli/main.c > CMakeFiles/inli.dir/main.c.i

CMakeFiles/inli.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/inli.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lqc/CLionProjects/inli/main.c -o CMakeFiles/inli.dir/main.c.s

# Object files for target inli
inli_OBJECTS = \
"CMakeFiles/inli.dir/main.c.o"

# External object files for target inli
inli_EXTERNAL_OBJECTS =

inli: CMakeFiles/inli.dir/main.c.o
inli: CMakeFiles/inli.dir/build.make
inli: CMakeFiles/inli.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lqc/CLionProjects/inli/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable inli"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/inli.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/inli.dir/build: inli

.PHONY : CMakeFiles/inli.dir/build

CMakeFiles/inli.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/inli.dir/cmake_clean.cmake
.PHONY : CMakeFiles/inli.dir/clean

CMakeFiles/inli.dir/depend:
	cd /home/lqc/CLionProjects/inli/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lqc/CLionProjects/inli /home/lqc/CLionProjects/inli /home/lqc/CLionProjects/inli/cmake-build-debug /home/lqc/CLionProjects/inli/cmake-build-debug /home/lqc/CLionProjects/inli/cmake-build-debug/CMakeFiles/inli.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/inli.dir/depend

