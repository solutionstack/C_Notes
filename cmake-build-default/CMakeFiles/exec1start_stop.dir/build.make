# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /home/olu/opt/clion-2024.2/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/olu/opt/clion-2024.2/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/olu/Store/lang/C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/olu/Store/lang/C/cmake-build-default

# Include any dependencies generated for this target.
include CMakeFiles/exec1start_stop.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/exec1start_stop.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/exec1start_stop.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exec1start_stop.dir/flags.make

CMakeFiles/exec1start_stop.dir/unix/signal_stop_and_start.c.o: CMakeFiles/exec1start_stop.dir/flags.make
CMakeFiles/exec1start_stop.dir/unix/signal_stop_and_start.c.o: /media/olu/Store/lang/C/unix/signal_stop_and_start.c
CMakeFiles/exec1start_stop.dir/unix/signal_stop_and_start.c.o: CMakeFiles/exec1start_stop.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/media/olu/Store/lang/C/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/exec1start_stop.dir/unix/signal_stop_and_start.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/exec1start_stop.dir/unix/signal_stop_and_start.c.o -MF CMakeFiles/exec1start_stop.dir/unix/signal_stop_and_start.c.o.d -o CMakeFiles/exec1start_stop.dir/unix/signal_stop_and_start.c.o -c /media/olu/Store/lang/C/unix/signal_stop_and_start.c

CMakeFiles/exec1start_stop.dir/unix/signal_stop_and_start.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/exec1start_stop.dir/unix/signal_stop_and_start.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/olu/Store/lang/C/unix/signal_stop_and_start.c > CMakeFiles/exec1start_stop.dir/unix/signal_stop_and_start.c.i

CMakeFiles/exec1start_stop.dir/unix/signal_stop_and_start.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/exec1start_stop.dir/unix/signal_stop_and_start.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/olu/Store/lang/C/unix/signal_stop_and_start.c -o CMakeFiles/exec1start_stop.dir/unix/signal_stop_and_start.c.s

# Object files for target exec1start_stop
exec1start_stop_OBJECTS = \
"CMakeFiles/exec1start_stop.dir/unix/signal_stop_and_start.c.o"

# External object files for target exec1start_stop
exec1start_stop_EXTERNAL_OBJECTS =

exec1start_stop: CMakeFiles/exec1start_stop.dir/unix/signal_stop_and_start.c.o
exec1start_stop: CMakeFiles/exec1start_stop.dir/build.make
exec1start_stop: CMakeFiles/exec1start_stop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/media/olu/Store/lang/C/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable exec1start_stop"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exec1start_stop.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exec1start_stop.dir/build: exec1start_stop
.PHONY : CMakeFiles/exec1start_stop.dir/build

CMakeFiles/exec1start_stop.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exec1start_stop.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exec1start_stop.dir/clean

CMakeFiles/exec1start_stop.dir/depend:
	cd /media/olu/Store/lang/C/cmake-build-default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/olu/Store/lang/C /media/olu/Store/lang/C /media/olu/Store/lang/C/cmake-build-default /media/olu/Store/lang/C/cmake-build-default /media/olu/Store/lang/C/cmake-build-default/CMakeFiles/exec1start_stop.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/exec1start_stop.dir/depend

