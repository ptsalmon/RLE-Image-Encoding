# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ptssk\CLionProjects\Project3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ptssk\CLionProjects\Project3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project2.out.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/project2.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project2.out.dir/flags.make

CMakeFiles/project2.out.dir/src/main.cpp.obj: CMakeFiles/project2.out.dir/flags.make
CMakeFiles/project2.out.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ptssk\CLionProjects\Project3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project2.out.dir/src/main.cpp.obj"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\project2.out.dir\src\main.cpp.obj -c C:\Users\ptssk\CLionProjects\Project3\src\main.cpp

CMakeFiles/project2.out.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project2.out.dir/src/main.cpp.i"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ptssk\CLionProjects\Project3\src\main.cpp > CMakeFiles\project2.out.dir\src\main.cpp.i

CMakeFiles/project2.out.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project2.out.dir/src/main.cpp.s"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ptssk\CLionProjects\Project3\src\main.cpp -o CMakeFiles\project2.out.dir\src\main.cpp.s

CMakeFiles/project2.out.dir/src/Image.cpp.obj: CMakeFiles/project2.out.dir/flags.make
CMakeFiles/project2.out.dir/src/Image.cpp.obj: ../src/Image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ptssk\CLionProjects\Project3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project2.out.dir/src/Image.cpp.obj"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\project2.out.dir\src\Image.cpp.obj -c C:\Users\ptssk\CLionProjects\Project3\src\Image.cpp

CMakeFiles/project2.out.dir/src/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project2.out.dir/src/Image.cpp.i"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ptssk\CLionProjects\Project3\src\Image.cpp > CMakeFiles\project2.out.dir\src\Image.cpp.i

CMakeFiles/project2.out.dir/src/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project2.out.dir/src/Image.cpp.s"
	C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ptssk\CLionProjects\Project3\src\Image.cpp -o CMakeFiles\project2.out.dir\src\Image.cpp.s

# Object files for target project2.out
project2_out_OBJECTS = \
"CMakeFiles/project2.out.dir/src/main.cpp.obj" \
"CMakeFiles/project2.out.dir/src/Image.cpp.obj"

# External object files for target project2.out
project2_out_EXTERNAL_OBJECTS =

project2.out.exe: CMakeFiles/project2.out.dir/src/main.cpp.obj
project2.out.exe: CMakeFiles/project2.out.dir/src/Image.cpp.obj
project2.out.exe: CMakeFiles/project2.out.dir/build.make
project2.out.exe: CMakeFiles/project2.out.dir/linklibs.rsp
project2.out.exe: CMakeFiles/project2.out.dir/objects1.rsp
project2.out.exe: CMakeFiles/project2.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ptssk\CLionProjects\Project3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable project2.out.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\project2.out.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project2.out.dir/build: project2.out.exe
.PHONY : CMakeFiles/project2.out.dir/build

CMakeFiles/project2.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\project2.out.dir\cmake_clean.cmake
.PHONY : CMakeFiles/project2.out.dir/clean

CMakeFiles/project2.out.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ptssk\CLionProjects\Project3 C:\Users\ptssk\CLionProjects\Project3 C:\Users\ptssk\CLionProjects\Project3\cmake-build-debug C:\Users\ptssk\CLionProjects\Project3\cmake-build-debug C:\Users\ptssk\CLionProjects\Project3\cmake-build-debug\CMakeFiles\project2.out.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project2.out.dir/depend

