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
CMAKE_COMMAND = "F:\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Kuba\CLionProjects\JiPP2\Lab4\zestaw1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Kuba\CLionProjects\JiPP2\Lab4\zestaw1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/zestaw1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/zestaw1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zestaw1.dir/flags.make

CMakeFiles/zestaw1.dir/src/main.cpp.obj: CMakeFiles/zestaw1.dir/flags.make
CMakeFiles/zestaw1.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Kuba\CLionProjects\JiPP2\Lab4\zestaw1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zestaw1.dir/src/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\zestaw1.dir\src\main.cpp.obj -c C:\Users\Kuba\CLionProjects\JiPP2\Lab4\zestaw1\src\main.cpp

CMakeFiles/zestaw1.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zestaw1.dir/src/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Kuba\CLionProjects\JiPP2\Lab4\zestaw1\src\main.cpp > CMakeFiles\zestaw1.dir\src\main.cpp.i

CMakeFiles/zestaw1.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zestaw1.dir/src/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Kuba\CLionProjects\JiPP2\Lab4\zestaw1\src\main.cpp -o CMakeFiles\zestaw1.dir\src\main.cpp.s

# Object files for target zestaw1
zestaw1_OBJECTS = \
"CMakeFiles/zestaw1.dir/src/main.cpp.obj"

# External object files for target zestaw1
zestaw1_EXTERNAL_OBJECTS =

zestaw1.exe: CMakeFiles/zestaw1.dir/src/main.cpp.obj
zestaw1.exe: CMakeFiles/zestaw1.dir/build.make
zestaw1.exe: CMakeFiles/zestaw1.dir/linklibs.rsp
zestaw1.exe: CMakeFiles/zestaw1.dir/objects1.rsp
zestaw1.exe: CMakeFiles/zestaw1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Kuba\CLionProjects\JiPP2\Lab4\zestaw1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable zestaw1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\zestaw1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zestaw1.dir/build: zestaw1.exe
.PHONY : CMakeFiles/zestaw1.dir/build

CMakeFiles/zestaw1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\zestaw1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/zestaw1.dir/clean

CMakeFiles/zestaw1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Kuba\CLionProjects\JiPP2\Lab4\zestaw1 C:\Users\Kuba\CLionProjects\JiPP2\Lab4\zestaw1 C:\Users\Kuba\CLionProjects\JiPP2\Lab4\zestaw1\cmake-build-debug C:\Users\Kuba\CLionProjects\JiPP2\Lab4\zestaw1\cmake-build-debug C:\Users\Kuba\CLionProjects\JiPP2\Lab4\zestaw1\cmake-build-debug\CMakeFiles\zestaw1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zestaw1.dir/depend

