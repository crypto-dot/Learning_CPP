# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/carlosarbizu/CLionProjects/Learning_CPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/carlosarbizu/CLionProjects/Learning_CPP/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Testtester.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Testtester.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Testtester.dir/flags.make

CMakeFiles/Testtester.dir/Essential_C++_concepts/Testtester.cpp.o: CMakeFiles/Testtester.dir/flags.make
CMakeFiles/Testtester.dir/Essential_C++_concepts/Testtester.cpp.o: ../Essential\ C++\ concepts/Testtester.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/carlosarbizu/CLionProjects/Learning_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Testtester.dir/Essential_C++_concepts/Testtester.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Testtester.dir/Essential_C++_concepts/Testtester.cpp.o -c "/Users/carlosarbizu/CLionProjects/Learning_CPP/Essential C++ concepts/Testtester.cpp"

CMakeFiles/Testtester.dir/Essential_C++_concepts/Testtester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Testtester.dir/Essential_C++_concepts/Testtester.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/carlosarbizu/CLionProjects/Learning_CPP/Essential C++ concepts/Testtester.cpp" > CMakeFiles/Testtester.dir/Essential_C++_concepts/Testtester.cpp.i

CMakeFiles/Testtester.dir/Essential_C++_concepts/Testtester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Testtester.dir/Essential_C++_concepts/Testtester.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/carlosarbizu/CLionProjects/Learning_CPP/Essential C++ concepts/Testtester.cpp" -o CMakeFiles/Testtester.dir/Essential_C++_concepts/Testtester.cpp.s

# Object files for target Testtester
Testtester_OBJECTS = \
"CMakeFiles/Testtester.dir/Essential_C++_concepts/Testtester.cpp.o"

# External object files for target Testtester
Testtester_EXTERNAL_OBJECTS =

Testtester: CMakeFiles/Testtester.dir/Essential_C++_concepts/Testtester.cpp.o
Testtester: CMakeFiles/Testtester.dir/build.make
Testtester: CMakeFiles/Testtester.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/carlosarbizu/CLionProjects/Learning_CPP/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Testtester"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Testtester.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Testtester.dir/build: Testtester
.PHONY : CMakeFiles/Testtester.dir/build

CMakeFiles/Testtester.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Testtester.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Testtester.dir/clean

CMakeFiles/Testtester.dir/depend:
	cd /Users/carlosarbizu/CLionProjects/Learning_CPP/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/carlosarbizu/CLionProjects/Learning_CPP /Users/carlosarbizu/CLionProjects/Learning_CPP /Users/carlosarbizu/CLionProjects/Learning_CPP/cmake-build-debug /Users/carlosarbizu/CLionProjects/Learning_CPP/cmake-build-debug /Users/carlosarbizu/CLionProjects/Learning_CPP/cmake-build-debug/CMakeFiles/Testtester.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Testtester.dir/depend

