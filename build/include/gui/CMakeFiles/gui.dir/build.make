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
include include/gui/CMakeFiles/gui.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include include/gui/CMakeFiles/gui.dir/compiler_depend.make

# Include the progress variables for this target.
include include/gui/CMakeFiles/gui.dir/progress.make

# Include the compile flags for this target's objects.
include include/gui/CMakeFiles/gui.dir/flags.make

include/gui/CMakeFiles/gui.dir/src/StartMenu.cpp.obj: include/gui/CMakeFiles/gui.dir/flags.make
include/gui/CMakeFiles/gui.dir/src/StartMenu.cpp.obj: include/gui/CMakeFiles/gui.dir/includes_CXX.rsp
include/gui/CMakeFiles/gui.dir/src/StartMenu.cpp.obj: D:/cpp/Game/GameSiC/include/gui/src/StartMenu.cpp
include/gui/CMakeFiles/gui.dir/src/StartMenu.cpp.obj: include/gui/CMakeFiles/gui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\cpp\Game\GameSiC\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/gui/CMakeFiles/gui.dir/src/StartMenu.cpp.obj"
	cd /d D:\cpp\Game\GameSiC\build\include\gui && C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/gui/CMakeFiles/gui.dir/src/StartMenu.cpp.obj -MF CMakeFiles\gui.dir\src\StartMenu.cpp.obj.d -o CMakeFiles\gui.dir\src\StartMenu.cpp.obj -c D:\cpp\Game\GameSiC\include\gui\src\StartMenu.cpp

include/gui/CMakeFiles/gui.dir/src/StartMenu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gui.dir/src/StartMenu.cpp.i"
	cd /d D:\cpp\Game\GameSiC\build\include\gui && C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\cpp\Game\GameSiC\include\gui\src\StartMenu.cpp > CMakeFiles\gui.dir\src\StartMenu.cpp.i

include/gui/CMakeFiles/gui.dir/src/StartMenu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gui.dir/src/StartMenu.cpp.s"
	cd /d D:\cpp\Game\GameSiC\build\include\gui && C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\cpp\Game\GameSiC\include\gui\src\StartMenu.cpp -o CMakeFiles\gui.dir\src\StartMenu.cpp.s

include/gui/CMakeFiles/gui.dir/src/SettingsMenu.cpp.obj: include/gui/CMakeFiles/gui.dir/flags.make
include/gui/CMakeFiles/gui.dir/src/SettingsMenu.cpp.obj: include/gui/CMakeFiles/gui.dir/includes_CXX.rsp
include/gui/CMakeFiles/gui.dir/src/SettingsMenu.cpp.obj: D:/cpp/Game/GameSiC/include/gui/src/SettingsMenu.cpp
include/gui/CMakeFiles/gui.dir/src/SettingsMenu.cpp.obj: include/gui/CMakeFiles/gui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\cpp\Game\GameSiC\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object include/gui/CMakeFiles/gui.dir/src/SettingsMenu.cpp.obj"
	cd /d D:\cpp\Game\GameSiC\build\include\gui && C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/gui/CMakeFiles/gui.dir/src/SettingsMenu.cpp.obj -MF CMakeFiles\gui.dir\src\SettingsMenu.cpp.obj.d -o CMakeFiles\gui.dir\src\SettingsMenu.cpp.obj -c D:\cpp\Game\GameSiC\include\gui\src\SettingsMenu.cpp

include/gui/CMakeFiles/gui.dir/src/SettingsMenu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gui.dir/src/SettingsMenu.cpp.i"
	cd /d D:\cpp\Game\GameSiC\build\include\gui && C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\cpp\Game\GameSiC\include\gui\src\SettingsMenu.cpp > CMakeFiles\gui.dir\src\SettingsMenu.cpp.i

include/gui/CMakeFiles/gui.dir/src/SettingsMenu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gui.dir/src/SettingsMenu.cpp.s"
	cd /d D:\cpp\Game\GameSiC\build\include\gui && C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\cpp\Game\GameSiC\include\gui\src\SettingsMenu.cpp -o CMakeFiles\gui.dir\src\SettingsMenu.cpp.s

include/gui/CMakeFiles/gui.dir/src/SettingsAdvance.cpp.obj: include/gui/CMakeFiles/gui.dir/flags.make
include/gui/CMakeFiles/gui.dir/src/SettingsAdvance.cpp.obj: include/gui/CMakeFiles/gui.dir/includes_CXX.rsp
include/gui/CMakeFiles/gui.dir/src/SettingsAdvance.cpp.obj: D:/cpp/Game/GameSiC/include/gui/src/SettingsAdvance.cpp
include/gui/CMakeFiles/gui.dir/src/SettingsAdvance.cpp.obj: include/gui/CMakeFiles/gui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\cpp\Game\GameSiC\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object include/gui/CMakeFiles/gui.dir/src/SettingsAdvance.cpp.obj"
	cd /d D:\cpp\Game\GameSiC\build\include\gui && C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT include/gui/CMakeFiles/gui.dir/src/SettingsAdvance.cpp.obj -MF CMakeFiles\gui.dir\src\SettingsAdvance.cpp.obj.d -o CMakeFiles\gui.dir\src\SettingsAdvance.cpp.obj -c D:\cpp\Game\GameSiC\include\gui\src\SettingsAdvance.cpp

include/gui/CMakeFiles/gui.dir/src/SettingsAdvance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gui.dir/src/SettingsAdvance.cpp.i"
	cd /d D:\cpp\Game\GameSiC\build\include\gui && C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\cpp\Game\GameSiC\include\gui\src\SettingsAdvance.cpp > CMakeFiles\gui.dir\src\SettingsAdvance.cpp.i

include/gui/CMakeFiles/gui.dir/src/SettingsAdvance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gui.dir/src/SettingsAdvance.cpp.s"
	cd /d D:\cpp\Game\GameSiC\build\include\gui && C:\msys64\mingw64\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\cpp\Game\GameSiC\include\gui\src\SettingsAdvance.cpp -o CMakeFiles\gui.dir\src\SettingsAdvance.cpp.s

# Object files for target gui
gui_OBJECTS = \
"CMakeFiles/gui.dir/src/StartMenu.cpp.obj" \
"CMakeFiles/gui.dir/src/SettingsMenu.cpp.obj" \
"CMakeFiles/gui.dir/src/SettingsAdvance.cpp.obj"

# External object files for target gui
gui_EXTERNAL_OBJECTS =

include/gui/libgui.a: include/gui/CMakeFiles/gui.dir/src/StartMenu.cpp.obj
include/gui/libgui.a: include/gui/CMakeFiles/gui.dir/src/SettingsMenu.cpp.obj
include/gui/libgui.a: include/gui/CMakeFiles/gui.dir/src/SettingsAdvance.cpp.obj
include/gui/libgui.a: include/gui/CMakeFiles/gui.dir/build.make
include/gui/libgui.a: include/gui/CMakeFiles/gui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\cpp\Game\GameSiC\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libgui.a"
	cd /d D:\cpp\Game\GameSiC\build\include\gui && $(CMAKE_COMMAND) -P CMakeFiles\gui.dir\cmake_clean_target.cmake
	cd /d D:\cpp\Game\GameSiC\build\include\gui && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gui.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/gui/CMakeFiles/gui.dir/build: include/gui/libgui.a
.PHONY : include/gui/CMakeFiles/gui.dir/build

include/gui/CMakeFiles/gui.dir/clean:
	cd /d D:\cpp\Game\GameSiC\build\include\gui && $(CMAKE_COMMAND) -P CMakeFiles\gui.dir\cmake_clean.cmake
.PHONY : include/gui/CMakeFiles/gui.dir/clean

include/gui/CMakeFiles/gui.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\cpp\Game\GameSiC D:\cpp\Game\GameSiC\include\gui D:\cpp\Game\GameSiC\build D:\cpp\Game\GameSiC\build\include\gui D:\cpp\Game\GameSiC\build\include\gui\CMakeFiles\gui.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : include/gui/CMakeFiles/gui.dir/depend

