# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = D:\cmake-3.22.1-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = D:\cmake-3.22.1-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\test\CppCode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\test\CppCode\build

# Include any dependencies generated for this target.
include GLFW/CMakeFiles/WindowUI.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include GLFW/CMakeFiles/WindowUI.dir/compiler_depend.make

# Include the progress variables for this target.
include GLFW/CMakeFiles/WindowUI.dir/progress.make

# Include the compile flags for this target's objects.
include GLFW/CMakeFiles/WindowUI.dir/flags.make

GLFW/CMakeFiles/WindowUI.dir/Win32Instance.cpp.obj: GLFW/CMakeFiles/WindowUI.dir/flags.make
GLFW/CMakeFiles/WindowUI.dir/Win32Instance.cpp.obj: GLFW/CMakeFiles/WindowUI.dir/includes_CXX.rsp
GLFW/CMakeFiles/WindowUI.dir/Win32Instance.cpp.obj: ../GLFW/Win32Instance.cpp
GLFW/CMakeFiles/WindowUI.dir/Win32Instance.cpp.obj: GLFW/CMakeFiles/WindowUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\test\CppCode\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object GLFW/CMakeFiles/WindowUI.dir/Win32Instance.cpp.obj"
	cd /d E:\test\CppCode\build\GLFW && D:\tools\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT GLFW/CMakeFiles/WindowUI.dir/Win32Instance.cpp.obj -MF CMakeFiles\WindowUI.dir\Win32Instance.cpp.obj.d -o CMakeFiles\WindowUI.dir\Win32Instance.cpp.obj -c E:\test\CppCode\GLFW\Win32Instance.cpp

GLFW/CMakeFiles/WindowUI.dir/Win32Instance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WindowUI.dir/Win32Instance.cpp.i"
	cd /d E:\test\CppCode\build\GLFW && D:\tools\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\test\CppCode\GLFW\Win32Instance.cpp > CMakeFiles\WindowUI.dir\Win32Instance.cpp.i

GLFW/CMakeFiles/WindowUI.dir/Win32Instance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WindowUI.dir/Win32Instance.cpp.s"
	cd /d E:\test\CppCode\build\GLFW && D:\tools\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\test\CppCode\GLFW\Win32Instance.cpp -o CMakeFiles\WindowUI.dir\Win32Instance.cpp.s

# Object files for target WindowUI
WindowUI_OBJECTS = \
"CMakeFiles/WindowUI.dir/Win32Instance.cpp.obj"

# External object files for target WindowUI
WindowUI_EXTERNAL_OBJECTS =

../GLFW/publish/bin/libWindowUI.dll: GLFW/CMakeFiles/WindowUI.dir/Win32Instance.cpp.obj
../GLFW/publish/bin/libWindowUI.dll: GLFW/CMakeFiles/WindowUI.dir/build.make
../GLFW/publish/bin/libWindowUI.dll: ../Third_party/GLFW/lib-mingw-w64/libglfw3dll.a
../GLFW/publish/bin/libWindowUI.dll: C:/VulkanSDK/1.3.204.0/Lib/vulkan-1.lib
../GLFW/publish/bin/libWindowUI.dll: GLFW/CMakeFiles/WindowUI.dir/linklibs.rsp
../GLFW/publish/bin/libWindowUI.dll: GLFW/CMakeFiles/WindowUI.dir/objects1.rsp
../GLFW/publish/bin/libWindowUI.dll: GLFW/CMakeFiles/WindowUI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\test\CppCode\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ..\..\GLFW\publish\bin\libWindowUI.dll"
	cd /d E:\test\CppCode\build\GLFW && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\WindowUI.dir\link.txt --verbose=$(VERBOSE)
	cd /d E:\test\CppCode\build\GLFW && D:\cmake-3.22.1-windows-x86_64\bin\cmake.exe -E copy E:/test/CppCode/Third_party/GLFW/lib-mingw-w64/libglfw3dll.a C:/VulkanSDK/1.3.204.0/Lib/vulkan-1.lib E:/test/CppCode/GLFW/publish/bin
	cd /d E:\test\CppCode\build\GLFW && D:\cmake-3.22.1-windows-x86_64\bin\cmake.exe -E copy_directory E:/test/CppCode/Third_party/GLFW/lib-mingw-w64 E:/test/CppCode/GLFW/publish/bin

# Rule to build all files generated by this target.
GLFW/CMakeFiles/WindowUI.dir/build: ../GLFW/publish/bin/libWindowUI.dll
.PHONY : GLFW/CMakeFiles/WindowUI.dir/build

GLFW/CMakeFiles/WindowUI.dir/clean:
	cd /d E:\test\CppCode\build\GLFW && $(CMAKE_COMMAND) -P CMakeFiles\WindowUI.dir\cmake_clean.cmake
.PHONY : GLFW/CMakeFiles/WindowUI.dir/clean

GLFW/CMakeFiles/WindowUI.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\test\CppCode E:\test\CppCode\GLFW E:\test\CppCode\build E:\test\CppCode\build\GLFW E:\test\CppCode\build\GLFW\CMakeFiles\WindowUI.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : GLFW/CMakeFiles/WindowUI.dir/depend

