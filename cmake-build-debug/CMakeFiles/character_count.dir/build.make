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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/olubodunagbalaya/Documents/Books/c/learn

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/olubodunagbalaya/Documents/Books/c/learn/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/character_count.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/character_count.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/character_count.dir/flags.make

CMakeFiles/character_count.dir/character_count.c.o: CMakeFiles/character_count.dir/flags.make
CMakeFiles/character_count.dir/character_count.c.o: ../character_count.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/olubodunagbalaya/Documents/Books/c/learn/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/character_count.dir/character_count.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/character_count.dir/character_count.c.o   -c /Users/olubodunagbalaya/Documents/Books/c/learn/character_count.c

CMakeFiles/character_count.dir/character_count.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/character_count.dir/character_count.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/olubodunagbalaya/Documents/Books/c/learn/character_count.c > CMakeFiles/character_count.dir/character_count.c.i

CMakeFiles/character_count.dir/character_count.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/character_count.dir/character_count.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/olubodunagbalaya/Documents/Books/c/learn/character_count.c -o CMakeFiles/character_count.dir/character_count.c.s

# Object files for target character_count
character_count_OBJECTS = \
"CMakeFiles/character_count.dir/character_count.c.o"

# External object files for target character_count
character_count_EXTERNAL_OBJECTS =

character_count: CMakeFiles/character_count.dir/character_count.c.o
character_count: CMakeFiles/character_count.dir/build.make
character_count: CMakeFiles/character_count.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/olubodunagbalaya/Documents/Books/c/learn/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable character_count"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/character_count.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/character_count.dir/build: character_count

.PHONY : CMakeFiles/character_count.dir/build

CMakeFiles/character_count.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/character_count.dir/cmake_clean.cmake
.PHONY : CMakeFiles/character_count.dir/clean

CMakeFiles/character_count.dir/depend:
	cd /Users/olubodunagbalaya/Documents/Books/c/learn/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/olubodunagbalaya/Documents/Books/c/learn /Users/olubodunagbalaya/Documents/Books/c/learn /Users/olubodunagbalaya/Documents/Books/c/learn/cmake-build-debug /Users/olubodunagbalaya/Documents/Books/c/learn/cmake-build-debug /Users/olubodunagbalaya/Documents/Books/c/learn/cmake-build-debug/CMakeFiles/character_count.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/character_count.dir/depend

