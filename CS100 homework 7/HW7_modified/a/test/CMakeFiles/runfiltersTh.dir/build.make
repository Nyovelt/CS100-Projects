# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/Nyove/Downloads/HW7/HW7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Nyove/Downloads/HW7/HW7/a

# Include any dependencies generated for this target.
include test/CMakeFiles/runfiltersTh.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/runfiltersTh.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/runfiltersTh.dir/flags.make

test/CMakeFiles/runfiltersTh.dir/test3.cpp.o: test/CMakeFiles/runfiltersTh.dir/flags.make
test/CMakeFiles/runfiltersTh.dir/test3.cpp.o: ../test/test3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Nyove/Downloads/HW7/HW7/a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/runfiltersTh.dir/test3.cpp.o"
	cd /mnt/c/Users/Nyove/Downloads/HW7/HW7/a/test && /usr/sbin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runfiltersTh.dir/test3.cpp.o -c /mnt/c/Users/Nyove/Downloads/HW7/HW7/test/test3.cpp

test/CMakeFiles/runfiltersTh.dir/test3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runfiltersTh.dir/test3.cpp.i"
	cd /mnt/c/Users/Nyove/Downloads/HW7/HW7/a/test && /usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Nyove/Downloads/HW7/HW7/test/test3.cpp > CMakeFiles/runfiltersTh.dir/test3.cpp.i

test/CMakeFiles/runfiltersTh.dir/test3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runfiltersTh.dir/test3.cpp.s"
	cd /mnt/c/Users/Nyove/Downloads/HW7/HW7/a/test && /usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Nyove/Downloads/HW7/HW7/test/test3.cpp -o CMakeFiles/runfiltersTh.dir/test3.cpp.s

# Object files for target runfiltersTh
runfiltersTh_OBJECTS = \
"CMakeFiles/runfiltersTh.dir/test3.cpp.o"

# External object files for target runfiltersTh
runfiltersTh_EXTERNAL_OBJECTS =

test/runfiltersTh: test/CMakeFiles/runfiltersTh.dir/test3.cpp.o
test/runfiltersTh: test/CMakeFiles/runfiltersTh.dir/build.make
test/runfiltersTh: src/libimagefiltering.a
test/runfiltersTh: test/CMakeFiles/runfiltersTh.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Nyove/Downloads/HW7/HW7/a/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable runfiltersTh"
	cd /mnt/c/Users/Nyove/Downloads/HW7/HW7/a/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runfiltersTh.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/runfiltersTh.dir/build: test/runfiltersTh

.PHONY : test/CMakeFiles/runfiltersTh.dir/build

test/CMakeFiles/runfiltersTh.dir/clean:
	cd /mnt/c/Users/Nyove/Downloads/HW7/HW7/a/test && $(CMAKE_COMMAND) -P CMakeFiles/runfiltersTh.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/runfiltersTh.dir/clean

test/CMakeFiles/runfiltersTh.dir/depend:
	cd /mnt/c/Users/Nyove/Downloads/HW7/HW7/a && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Nyove/Downloads/HW7/HW7 /mnt/c/Users/Nyove/Downloads/HW7/HW7/test /mnt/c/Users/Nyove/Downloads/HW7/HW7/a /mnt/c/Users/Nyove/Downloads/HW7/HW7/a/test /mnt/c/Users/Nyove/Downloads/HW7/HW7/a/test/CMakeFiles/runfiltersTh.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/runfiltersTh.dir/depend

