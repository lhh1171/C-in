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
CMAKE_SOURCE_DIR = /home/lqc/CLionProjects/c++-in

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lqc/CLionProjects/c++-in/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/c___in.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/c___in.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/c___in.dir/flags.make

CMakeFiles/c___in.dir/main.cpp.o: CMakeFiles/c___in.dir/flags.make
CMakeFiles/c___in.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lqc/CLionProjects/c++-in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/c___in.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/c___in.dir/main.cpp.o -c /home/lqc/CLionProjects/c++-in/main.cpp

CMakeFiles/c___in.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c___in.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lqc/CLionProjects/c++-in/main.cpp > CMakeFiles/c___in.dir/main.cpp.i

CMakeFiles/c___in.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c___in.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lqc/CLionProjects/c++-in/main.cpp -o CMakeFiles/c___in.dir/main.cpp.s

# Object files for target c___in
c___in_OBJECTS = \
"CMakeFiles/c___in.dir/main.cpp.o"

# External object files for target c___in
c___in_EXTERNAL_OBJECTS =

c___in: CMakeFiles/c___in.dir/main.cpp.o
c___in: CMakeFiles/c___in.dir/build.make
c___in: CMakeFiles/c___in.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lqc/CLionProjects/c++-in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable c___in"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/c___in.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/c___in.dir/build: c___in

.PHONY : CMakeFiles/c___in.dir/build

CMakeFiles/c___in.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/c___in.dir/cmake_clean.cmake
.PHONY : CMakeFiles/c___in.dir/clean

CMakeFiles/c___in.dir/depend:
	cd /home/lqc/CLionProjects/c++-in/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lqc/CLionProjects/c++-in /home/lqc/CLionProjects/c++-in /home/lqc/CLionProjects/c++-in/cmake-build-debug /home/lqc/CLionProjects/c++-in/cmake-build-debug /home/lqc/CLionProjects/c++-in/cmake-build-debug/CMakeFiles/c___in.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/c___in.dir/depend

