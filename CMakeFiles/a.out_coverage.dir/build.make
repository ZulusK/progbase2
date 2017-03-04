# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/zulus/Projects/GitProj/progbase2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zulus/Projects/GitProj/progbase2

# Utility rule file for a.out_coverage.

# Include the progress variables for this target.
include CMakeFiles/a.out_coverage.dir/progress.make

CMakeFiles/a.out_coverage:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zulus/Projects/GitProj/progbase2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Resetting code coverage counters to zero."
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Processing code coverage counters and generating report."
	/usr/bin/lcov --directory . --zerocounters
	/home/zulus/Projects/GitProj/progbase2/a.out
	/usr/bin/lcov --directory . --capture --output-file /home/zulus/Projects/GitProj/progbase2/coverage.info
	/usr/bin/lcov --remove /home/zulus/Projects/GitProj/progbase2/coverage.info 'tests/*' '/usr/*' --output-file /home/zulus/Projects/GitProj/progbase2/coverage.info.cleaned
	/usr/bin/genhtml -o coverage /home/zulus/Projects/GitProj/progbase2/coverage.info.cleaned
	/usr/bin/cmake -E remove /home/zulus/Projects/GitProj/progbase2/coverage.info /home/zulus/Projects/GitProj/progbase2/coverage.info.cleaned

a.out_coverage: CMakeFiles/a.out_coverage
a.out_coverage: CMakeFiles/a.out_coverage.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Open ./coverage/index.html in your browser to view the coverage report."
.PHONY : a.out_coverage

# Rule to build all files generated by this target.
CMakeFiles/a.out_coverage.dir/build: a.out_coverage

.PHONY : CMakeFiles/a.out_coverage.dir/build

CMakeFiles/a.out_coverage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a.out_coverage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a.out_coverage.dir/clean

CMakeFiles/a.out_coverage.dir/depend:
	cd /home/zulus/Projects/GitProj/progbase2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zulus/Projects/GitProj/progbase2 /home/zulus/Projects/GitProj/progbase2 /home/zulus/Projects/GitProj/progbase2 /home/zulus/Projects/GitProj/progbase2 /home/zulus/Projects/GitProj/progbase2/CMakeFiles/a.out_coverage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a.out_coverage.dir/depend

