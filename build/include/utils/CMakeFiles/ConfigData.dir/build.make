# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\cpp\Game\GameSiC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\cpp\Game\GameSiC\build

# Include any dependencies generated for this target.
include include/utils/CMakeFiles/ConfigData.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include include/utils/CMakeFiles/ConfigData.dir/compiler_depend.make

# Include the progress variables for this target.
include include/utils/CMakeFiles/ConfigData.dir/progress.make

# Include the compile flags for this target's objects.
include include/utils/CMakeFiles/ConfigData.dir/flags.make

include/utils/CMakeFiles/ConfigData.dir/src/ConfigData.cpp.obj: include/utils/CMakeFiles/ConfigData.dir/flags.make
include/utils/CMakeFiles/ConfigData.dir/src/ConfigData.cpp.obj: D:/cpp/Game/GameSiC/include/utils/src/ConfigData.cpp
include/utils/CMakeFiles/ConfigData.dir/src/ConfigData.cpp.obj: include/utils/CMakeFiles/ConfigData.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\cpp\Game\GameSiC\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/utils/CMakeFiles/ConfigData.dir/src/ConfigData.cpp.obj"
	cd /d D:\cpp\Game\GameSiC\build\include\utils && C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/utils/CMakeFiles/ConfigData.dir/src/ConfigData.cpp.obj -MF CMakeFiles\ConfigData.dir\src\ConfigData.cpp.obj.d -o CMakeFiles\ConfigData.dir\src\ConfigData.cpp.obj -c D:\cpp\Game\GameSiC\include\utils\src\ConfigData.cpp

include/utils/CMakeFiles/ConfigData.dir/src/ConfigData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ConfigData.dir/src/ConfigData.cpp.i"
	cd /d D:\cpp\Game\GameSiC\build\include\utils && C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\cpp\Game\GameSiC\include\utils\src\ConfigData.cpp > CMakeFiles\ConfigData.dir\src\ConfigData.cpp.i

include/utils/CMakeFiles/ConfigData.dir/src/ConfigData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ConfigData.dir/src/ConfigData.cpp.s"
	cd /d D:\cpp\Game\GameSiC\build\include\utils && C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\cpp\Game\GameSiC\include\utils\src\ConfigData.cpp -o CMakeFiles\ConfigData.dir\src\ConfigData.cpp.s

# Object files for target ConfigData
ConfigData_OBJECTS = \
"CMakeFiles/ConfigData.dir/src/ConfigData.cpp.obj"

# External object files for target ConfigData
ConfigData_EXTERNAL_OBJECTS =

include/utils/ConfigData.exe: include/utils/CMakeFiles/ConfigData.dir/src/ConfigData.cpp.obj
include/utils/ConfigData.exe: include/utils/CMakeFiles/ConfigData.dir/build.make
include/utils/ConfigData.exe: include/utils/CMakeFiles/ConfigData.dir/linkLibs.rsp
include/utils/ConfigData.exe: include/utils/CMakeFiles/ConfigData.dir/objects1.rsp
include/utils/ConfigData.exe: include/utils/CMakeFiles/ConfigData.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\cpp\Game\GameSiC\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ConfigData.exe"
	cd /d D:\cpp\Game\GameSiC\build\include\utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ConfigData.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/utils/CMakeFiles/ConfigData.dir/build: include/utils/ConfigData.exe
.PHONY : include/utils/CMakeFiles/ConfigData.dir/build

include/utils/CMakeFiles/ConfigData.dir/clean:
	cd /d D:\cpp\Game\GameSiC\build\include\utils && $(CMAKE_COMMAND) -P CMakeFiles\ConfigData.dir\cmake_clean.cmake
.PHONY : include/utils/CMakeFiles/ConfigData.dir/clean

include/utils/CMakeFiles/ConfigData.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\cpp\Game\GameSiC D:\cpp\Game\GameSiC\include\utils D:\cpp\Game\GameSiC\build D:\cpp\Game\GameSiC\build\include\utils D:\cpp\Game\GameSiC\build\include\utils\CMakeFiles\ConfigData.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : include/utils/CMakeFiles/ConfigData.dir/depend

