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

# Include any dependencies generated for this target.
include CMakeFiles/university.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/university.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/university.dir/flags.make

CMakeFiles/university.dir/src/lecturer.c.o: CMakeFiles/university.dir/flags.make
CMakeFiles/university.dir/src/lecturer.c.o: src/lecturer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zulus/Projects/GitProj/progbase2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/university.dir/src/lecturer.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/university.dir/src/lecturer.c.o   -c /home/zulus/Projects/GitProj/progbase2/src/lecturer.c

CMakeFiles/university.dir/src/lecturer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/university.dir/src/lecturer.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zulus/Projects/GitProj/progbase2/src/lecturer.c > CMakeFiles/university.dir/src/lecturer.c.i

CMakeFiles/university.dir/src/lecturer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/university.dir/src/lecturer.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zulus/Projects/GitProj/progbase2/src/lecturer.c -o CMakeFiles/university.dir/src/lecturer.c.s

CMakeFiles/university.dir/src/lecturer.c.o.requires:

.PHONY : CMakeFiles/university.dir/src/lecturer.c.o.requires

CMakeFiles/university.dir/src/lecturer.c.o.provides: CMakeFiles/university.dir/src/lecturer.c.o.requires
	$(MAKE) -f CMakeFiles/university.dir/build.make CMakeFiles/university.dir/src/lecturer.c.o.provides.build
.PHONY : CMakeFiles/university.dir/src/lecturer.c.o.provides

CMakeFiles/university.dir/src/lecturer.c.o.provides.build: CMakeFiles/university.dir/src/lecturer.c.o


CMakeFiles/university.dir/src/student.c.o: CMakeFiles/university.dir/flags.make
CMakeFiles/university.dir/src/student.c.o: src/student.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zulus/Projects/GitProj/progbase2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/university.dir/src/student.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/university.dir/src/student.c.o   -c /home/zulus/Projects/GitProj/progbase2/src/student.c

CMakeFiles/university.dir/src/student.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/university.dir/src/student.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zulus/Projects/GitProj/progbase2/src/student.c > CMakeFiles/university.dir/src/student.c.i

CMakeFiles/university.dir/src/student.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/university.dir/src/student.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zulus/Projects/GitProj/progbase2/src/student.c -o CMakeFiles/university.dir/src/student.c.s

CMakeFiles/university.dir/src/student.c.o.requires:

.PHONY : CMakeFiles/university.dir/src/student.c.o.requires

CMakeFiles/university.dir/src/student.c.o.provides: CMakeFiles/university.dir/src/student.c.o.requires
	$(MAKE) -f CMakeFiles/university.dir/build.make CMakeFiles/university.dir/src/student.c.o.provides.build
.PHONY : CMakeFiles/university.dir/src/student.c.o.provides

CMakeFiles/university.dir/src/student.c.o.provides.build: CMakeFiles/university.dir/src/student.c.o


CMakeFiles/university.dir/src/collection/dlList.c.o: CMakeFiles/university.dir/flags.make
CMakeFiles/university.dir/src/collection/dlList.c.o: src/collection/dlList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zulus/Projects/GitProj/progbase2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/university.dir/src/collection/dlList.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/university.dir/src/collection/dlList.c.o   -c /home/zulus/Projects/GitProj/progbase2/src/collection/dlList.c

CMakeFiles/university.dir/src/collection/dlList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/university.dir/src/collection/dlList.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zulus/Projects/GitProj/progbase2/src/collection/dlList.c > CMakeFiles/university.dir/src/collection/dlList.c.i

CMakeFiles/university.dir/src/collection/dlList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/university.dir/src/collection/dlList.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zulus/Projects/GitProj/progbase2/src/collection/dlList.c -o CMakeFiles/university.dir/src/collection/dlList.c.s

CMakeFiles/university.dir/src/collection/dlList.c.o.requires:

.PHONY : CMakeFiles/university.dir/src/collection/dlList.c.o.requires

CMakeFiles/university.dir/src/collection/dlList.c.o.provides: CMakeFiles/university.dir/src/collection/dlList.c.o.requires
	$(MAKE) -f CMakeFiles/university.dir/build.make CMakeFiles/university.dir/src/collection/dlList.c.o.provides.build
.PHONY : CMakeFiles/university.dir/src/collection/dlList.c.o.provides

CMakeFiles/university.dir/src/collection/dlList.c.o.provides.build: CMakeFiles/university.dir/src/collection/dlList.c.o


CMakeFiles/university.dir/src/collection/dlNode.c.o: CMakeFiles/university.dir/flags.make
CMakeFiles/university.dir/src/collection/dlNode.c.o: src/collection/dlNode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zulus/Projects/GitProj/progbase2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/university.dir/src/collection/dlNode.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/university.dir/src/collection/dlNode.c.o   -c /home/zulus/Projects/GitProj/progbase2/src/collection/dlNode.c

CMakeFiles/university.dir/src/collection/dlNode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/university.dir/src/collection/dlNode.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zulus/Projects/GitProj/progbase2/src/collection/dlNode.c > CMakeFiles/university.dir/src/collection/dlNode.c.i

CMakeFiles/university.dir/src/collection/dlNode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/university.dir/src/collection/dlNode.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zulus/Projects/GitProj/progbase2/src/collection/dlNode.c -o CMakeFiles/university.dir/src/collection/dlNode.c.s

CMakeFiles/university.dir/src/collection/dlNode.c.o.requires:

.PHONY : CMakeFiles/university.dir/src/collection/dlNode.c.o.requires

CMakeFiles/university.dir/src/collection/dlNode.c.o.provides: CMakeFiles/university.dir/src/collection/dlNode.c.o.requires
	$(MAKE) -f CMakeFiles/university.dir/build.make CMakeFiles/university.dir/src/collection/dlNode.c.o.provides.build
.PHONY : CMakeFiles/university.dir/src/collection/dlNode.c.o.provides

CMakeFiles/university.dir/src/collection/dlNode.c.o.provides.build: CMakeFiles/university.dir/src/collection/dlNode.c.o


# Object files for target university
university_OBJECTS = \
"CMakeFiles/university.dir/src/lecturer.c.o" \
"CMakeFiles/university.dir/src/student.c.o" \
"CMakeFiles/university.dir/src/collection/dlList.c.o" \
"CMakeFiles/university.dir/src/collection/dlNode.c.o"

# External object files for target university
university_EXTERNAL_OBJECTS =

libuniversity.a: CMakeFiles/university.dir/src/lecturer.c.o
libuniversity.a: CMakeFiles/university.dir/src/student.c.o
libuniversity.a: CMakeFiles/university.dir/src/collection/dlList.c.o
libuniversity.a: CMakeFiles/university.dir/src/collection/dlNode.c.o
libuniversity.a: CMakeFiles/university.dir/build.make
libuniversity.a: CMakeFiles/university.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zulus/Projects/GitProj/progbase2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C static library libuniversity.a"
	$(CMAKE_COMMAND) -P CMakeFiles/university.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/university.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/university.dir/build: libuniversity.a

.PHONY : CMakeFiles/university.dir/build

CMakeFiles/university.dir/requires: CMakeFiles/university.dir/src/lecturer.c.o.requires
CMakeFiles/university.dir/requires: CMakeFiles/university.dir/src/student.c.o.requires
CMakeFiles/university.dir/requires: CMakeFiles/university.dir/src/collection/dlList.c.o.requires
CMakeFiles/university.dir/requires: CMakeFiles/university.dir/src/collection/dlNode.c.o.requires

.PHONY : CMakeFiles/university.dir/requires

CMakeFiles/university.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/university.dir/cmake_clean.cmake
.PHONY : CMakeFiles/university.dir/clean

CMakeFiles/university.dir/depend:
	cd /home/zulus/Projects/GitProj/progbase2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zulus/Projects/GitProj/progbase2 /home/zulus/Projects/GitProj/progbase2 /home/zulus/Projects/GitProj/progbase2 /home/zulus/Projects/GitProj/progbase2 /home/zulus/Projects/GitProj/progbase2/CMakeFiles/university.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/university.dir/depend

