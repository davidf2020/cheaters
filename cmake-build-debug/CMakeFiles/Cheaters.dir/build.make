# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/davidfernandez/EE312/Cheaters

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/davidfernandez/EE312/Cheaters/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Cheaters.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Cheaters.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Cheaters.dir/flags.make

CMakeFiles/Cheaters.dir/plagiarismCatcher.cpp.o: CMakeFiles/Cheaters.dir/flags.make
CMakeFiles/Cheaters.dir/plagiarismCatcher.cpp.o: ../plagiarismCatcher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/davidfernandez/EE312/Cheaters/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Cheaters.dir/plagiarismCatcher.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Cheaters.dir/plagiarismCatcher.cpp.o -c /Users/davidfernandez/EE312/Cheaters/plagiarismCatcher.cpp

CMakeFiles/Cheaters.dir/plagiarismCatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cheaters.dir/plagiarismCatcher.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/davidfernandez/EE312/Cheaters/plagiarismCatcher.cpp > CMakeFiles/Cheaters.dir/plagiarismCatcher.cpp.i

CMakeFiles/Cheaters.dir/plagiarismCatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cheaters.dir/plagiarismCatcher.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/davidfernandez/EE312/Cheaters/plagiarismCatcher.cpp -o CMakeFiles/Cheaters.dir/plagiarismCatcher.cpp.s

# Object files for target Cheaters
Cheaters_OBJECTS = \
"CMakeFiles/Cheaters.dir/plagiarismCatcher.cpp.o"

# External object files for target Cheaters
Cheaters_EXTERNAL_OBJECTS =

Cheaters: CMakeFiles/Cheaters.dir/plagiarismCatcher.cpp.o
Cheaters: CMakeFiles/Cheaters.dir/build.make
Cheaters: CMakeFiles/Cheaters.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/davidfernandez/EE312/Cheaters/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Cheaters"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Cheaters.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Cheaters.dir/build: Cheaters

.PHONY : CMakeFiles/Cheaters.dir/build

CMakeFiles/Cheaters.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Cheaters.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Cheaters.dir/clean

CMakeFiles/Cheaters.dir/depend:
	cd /Users/davidfernandez/EE312/Cheaters/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/davidfernandez/EE312/Cheaters /Users/davidfernandez/EE312/Cheaters /Users/davidfernandez/EE312/Cheaters/cmake-build-debug /Users/davidfernandez/EE312/Cheaters/cmake-build-debug /Users/davidfernandez/EE312/Cheaters/cmake-build-debug/CMakeFiles/Cheaters.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Cheaters.dir/depend

