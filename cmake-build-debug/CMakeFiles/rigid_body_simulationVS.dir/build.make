# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.1.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.1.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\DUYAN\Documents\GitHub\rigid_body_simulationVS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\DUYAN\Documents\GitHub\rigid_body_simulationVS\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rigid_body_simulationVS.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/rigid_body_simulationVS.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rigid_body_simulationVS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rigid_body_simulationVS.dir/flags.make

CMakeFiles/rigid_body_simulationVS.dir/main.cpp.obj: CMakeFiles/rigid_body_simulationVS.dir/flags.make
CMakeFiles/rigid_body_simulationVS.dir/main.cpp.obj: CMakeFiles/rigid_body_simulationVS.dir/includes_CXX.rsp
CMakeFiles/rigid_body_simulationVS.dir/main.cpp.obj: C:/Users/DUYAN/Documents/GitHub/rigid_body_simulationVS/main.cpp
CMakeFiles/rigid_body_simulationVS.dir/main.cpp.obj: CMakeFiles/rigid_body_simulationVS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\DUYAN\Documents\GitHub\rigid_body_simulationVS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rigid_body_simulationVS.dir/main.cpp.obj"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rigid_body_simulationVS.dir/main.cpp.obj -MF CMakeFiles\rigid_body_simulationVS.dir\main.cpp.obj.d -o CMakeFiles\rigid_body_simulationVS.dir\main.cpp.obj -c C:\Users\DUYAN\Documents\GitHub\rigid_body_simulationVS\main.cpp

CMakeFiles/rigid_body_simulationVS.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rigid_body_simulationVS.dir/main.cpp.i"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\DUYAN\Documents\GitHub\rigid_body_simulationVS\main.cpp > CMakeFiles\rigid_body_simulationVS.dir\main.cpp.i

CMakeFiles/rigid_body_simulationVS.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rigid_body_simulationVS.dir/main.cpp.s"
	C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\DUYAN\Documents\GitHub\rigid_body_simulationVS\main.cpp -o CMakeFiles\rigid_body_simulationVS.dir\main.cpp.s

# Object files for target rigid_body_simulationVS
rigid_body_simulationVS_OBJECTS = \
"CMakeFiles/rigid_body_simulationVS.dir/main.cpp.obj"

# External object files for target rigid_body_simulationVS
rigid_body_simulationVS_EXTERNAL_OBJECTS =

rigid_body_simulationVS.exe: CMakeFiles/rigid_body_simulationVS.dir/main.cpp.obj
rigid_body_simulationVS.exe: CMakeFiles/rigid_body_simulationVS.dir/build.make
rigid_body_simulationVS.exe: C:/Users/DUYAN/Documents/GitHub/rigid_body_simulationVS/SDL2-2.26.5/x86_64-w64-mingw32/lib/libSDL2main.a
rigid_body_simulationVS.exe: C:/Users/DUYAN/Documents/GitHub/rigid_body_simulationVS/SDL2-2.26.5/x86_64-w64-mingw32/lib/libSDL2.dll.a
rigid_body_simulationVS.exe: CMakeFiles/rigid_body_simulationVS.dir/linkLibs.rsp
rigid_body_simulationVS.exe: CMakeFiles/rigid_body_simulationVS.dir/objects1
rigid_body_simulationVS.exe: CMakeFiles/rigid_body_simulationVS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\DUYAN\Documents\GitHub\rigid_body_simulationVS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rigid_body_simulationVS.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\rigid_body_simulationVS.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rigid_body_simulationVS.dir/build: rigid_body_simulationVS.exe
.PHONY : CMakeFiles/rigid_body_simulationVS.dir/build

CMakeFiles/rigid_body_simulationVS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\rigid_body_simulationVS.dir\cmake_clean.cmake
.PHONY : CMakeFiles/rigid_body_simulationVS.dir/clean

CMakeFiles/rigid_body_simulationVS.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\DUYAN\Documents\GitHub\rigid_body_simulationVS C:\Users\DUYAN\Documents\GitHub\rigid_body_simulationVS C:\Users\DUYAN\Documents\GitHub\rigid_body_simulationVS\cmake-build-debug C:\Users\DUYAN\Documents\GitHub\rigid_body_simulationVS\cmake-build-debug C:\Users\DUYAN\Documents\GitHub\rigid_body_simulationVS\cmake-build-debug\CMakeFiles\rigid_body_simulationVS.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rigid_body_simulationVS.dir/depend

