# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/Barth/Documents/ETH Zurich/Programming Techniques/Excercises/Ex02/build"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/Barth/Documents/ETH Zurich/Programming Techniques/Excercises/Ex02/build"

# Include any dependencies generated for this target.
include CMakeFiles/simpson.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simpson.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simpson.dir/flags.make

CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.o: CMakeFiles/simpson.dir/flags.make
CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.o: /Users/Barth/Documents/ETH\ Zurich/Programming\ Techniques/Excercises/Ex02/src/simpson.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Barth/Documents/ETH Zurich/Programming Techniques/Excercises/Ex02/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.o -c "/Users/Barth/Documents/ETH Zurich/Programming Techniques/Excercises/Ex02/src/simpson.cpp"

CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Barth/Documents/ETH Zurich/Programming Techniques/Excercises/Ex02/src/simpson.cpp" > CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.i

CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Barth/Documents/ETH Zurich/Programming Techniques/Excercises/Ex02/src/simpson.cpp" -o CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.s

CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.o.requires:

.PHONY : CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.o.requires

CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.o.provides: CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.o.requires
	$(MAKE) -f CMakeFiles/simpson.dir/build.make CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.o.provides.build
.PHONY : CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.o.provides

CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.o.provides.build: CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.o


# Object files for target simpson
simpson_OBJECTS = \
"CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.o"

# External object files for target simpson
simpson_EXTERNAL_OBJECTS =

libsimpson.dylib: CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.o
libsimpson.dylib: CMakeFiles/simpson.dir/build.make
libsimpson.dylib: CMakeFiles/simpson.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/Barth/Documents/ETH Zurich/Programming Techniques/Excercises/Ex02/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libsimpson.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simpson.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simpson.dir/build: libsimpson.dylib

.PHONY : CMakeFiles/simpson.dir/build

CMakeFiles/simpson.dir/requires: CMakeFiles/simpson.dir/Users/Barth/Documents/ETH_Zurich/Programming_Techniques/Excercises/Ex02/src/simpson.cpp.o.requires

.PHONY : CMakeFiles/simpson.dir/requires

CMakeFiles/simpson.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simpson.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simpson.dir/clean

CMakeFiles/simpson.dir/depend:
	cd "/Users/Barth/Documents/ETH Zurich/Programming Techniques/Excercises/Ex02/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/Barth/Documents/ETH Zurich/Programming Techniques/Excercises/Ex02/build" "/Users/Barth/Documents/ETH Zurich/Programming Techniques/Excercises/Ex02/build" "/Users/Barth/Documents/ETH Zurich/Programming Techniques/Excercises/Ex02/build" "/Users/Barth/Documents/ETH Zurich/Programming Techniques/Excercises/Ex02/build" "/Users/Barth/Documents/ETH Zurich/Programming Techniques/Excercises/Ex02/build/CMakeFiles/simpson.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/simpson.dir/depend
