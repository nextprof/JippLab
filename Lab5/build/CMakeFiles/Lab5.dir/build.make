# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\cmake-3.19.0-win64-x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\cmake-3.19.0-win64-x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\kubab\OneDrive\Pulpit\JIPP2\Lab5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\kubab\OneDrive\Pulpit\JIPP2\Lab5\build

# Include any dependencies generated for this target.
include CMakeFiles/Lab5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab5.dir/flags.make

CMakeFiles/Lab5.dir/src/main.cpp.obj: CMakeFiles/Lab5.dir/flags.make
CMakeFiles/Lab5.dir/src/main.cpp.obj: CMakeFiles/Lab5.dir/includes_CXX.rsp
CMakeFiles/Lab5.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kubab\OneDrive\Pulpit\JIPP2\Lab5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab5.dir/src/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab5.dir\src\main.cpp.obj -c C:\Users\kubab\OneDrive\Pulpit\JIPP2\Lab5\src\main.cpp

CMakeFiles/Lab5.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab5.dir/src/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kubab\OneDrive\Pulpit\JIPP2\Lab5\src\main.cpp > CMakeFiles\Lab5.dir\src\main.cpp.i

CMakeFiles/Lab5.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab5.dir/src/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kubab\OneDrive\Pulpit\JIPP2\Lab5\src\main.cpp -o CMakeFiles\Lab5.dir\src\main.cpp.s

CMakeFiles/Lab5.dir/src/matrix.cpp.obj: CMakeFiles/Lab5.dir/flags.make
CMakeFiles/Lab5.dir/src/matrix.cpp.obj: CMakeFiles/Lab5.dir/includes_CXX.rsp
CMakeFiles/Lab5.dir/src/matrix.cpp.obj: ../src/matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kubab\OneDrive\Pulpit\JIPP2\Lab5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab5.dir/src/matrix.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab5.dir\src\matrix.cpp.obj -c C:\Users\kubab\OneDrive\Pulpit\JIPP2\Lab5\src\matrix.cpp

CMakeFiles/Lab5.dir/src/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab5.dir/src/matrix.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kubab\OneDrive\Pulpit\JIPP2\Lab5\src\matrix.cpp > CMakeFiles\Lab5.dir\src\matrix.cpp.i

CMakeFiles/Lab5.dir/src/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab5.dir/src/matrix.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kubab\OneDrive\Pulpit\JIPP2\Lab5\src\matrix.cpp -o CMakeFiles\Lab5.dir\src\matrix.cpp.s

# Object files for target Lab5
Lab5_OBJECTS = \
"CMakeFiles/Lab5.dir/src/main.cpp.obj" \
"CMakeFiles/Lab5.dir/src/matrix.cpp.obj"

# External object files for target Lab5
Lab5_EXTERNAL_OBJECTS =

Lab5.exe: CMakeFiles/Lab5.dir/src/main.cpp.obj
Lab5.exe: CMakeFiles/Lab5.dir/src/matrix.cpp.obj
Lab5.exe: CMakeFiles/Lab5.dir/build.make
Lab5.exe: CMakeFiles/Lab5.dir/linklibs.rsp
Lab5.exe: CMakeFiles/Lab5.dir/objects1.rsp
Lab5.exe: CMakeFiles/Lab5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\kubab\OneDrive\Pulpit\JIPP2\Lab5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Lab5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab5.dir/build: Lab5.exe

.PHONY : CMakeFiles/Lab5.dir/build

CMakeFiles/Lab5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab5.dir/clean

CMakeFiles/Lab5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\kubab\OneDrive\Pulpit\JIPP2\Lab5 C:\Users\kubab\OneDrive\Pulpit\JIPP2\Lab5 C:\Users\kubab\OneDrive\Pulpit\JIPP2\Lab5\build C:\Users\kubab\OneDrive\Pulpit\JIPP2\Lab5\build C:\Users\kubab\OneDrive\Pulpit\JIPP2\Lab5\build\CMakeFiles\Lab5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab5.dir/depend

