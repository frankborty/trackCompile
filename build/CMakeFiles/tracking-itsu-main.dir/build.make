# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fdessena/Desktop/trackCompile

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fdessena/Desktop/trackCompile/build

# Include any dependencies generated for this target.
include CMakeFiles/tracking-itsu-main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tracking-itsu-main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tracking-itsu-main.dir/flags.make

CMakeFiles/tracking-itsu-main.dir/main.cpp.o: CMakeFiles/tracking-itsu-main.dir/flags.make
CMakeFiles/tracking-itsu-main.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fdessena/Desktop/trackCompile/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tracking-itsu-main.dir/main.cpp.o"
	/opt/rh/devtoolset-6/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tracking-itsu-main.dir/main.cpp.o -c /home/fdessena/Desktop/trackCompile/main.cpp

CMakeFiles/tracking-itsu-main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tracking-itsu-main.dir/main.cpp.i"
	/opt/rh/devtoolset-6/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fdessena/Desktop/trackCompile/main.cpp > CMakeFiles/tracking-itsu-main.dir/main.cpp.i

CMakeFiles/tracking-itsu-main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tracking-itsu-main.dir/main.cpp.s"
	/opt/rh/devtoolset-6/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fdessena/Desktop/trackCompile/main.cpp -o CMakeFiles/tracking-itsu-main.dir/main.cpp.s

CMakeFiles/tracking-itsu-main.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/tracking-itsu-main.dir/main.cpp.o.requires

CMakeFiles/tracking-itsu-main.dir/main.cpp.o.provides: CMakeFiles/tracking-itsu-main.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/tracking-itsu-main.dir/build.make CMakeFiles/tracking-itsu-main.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/tracking-itsu-main.dir/main.cpp.o.provides

CMakeFiles/tracking-itsu-main.dir/main.cpp.o.provides.build: CMakeFiles/tracking-itsu-main.dir/main.cpp.o


# Object files for target tracking-itsu-main
tracking__itsu__main_OBJECTS = \
"CMakeFiles/tracking-itsu-main.dir/main.cpp.o"

# External object files for target tracking-itsu-main
tracking__itsu__main_EXTERNAL_OBJECTS =

tracking-itsu-main: CMakeFiles/tracking-itsu-main.dir/main.cpp.o
tracking-itsu-main: CMakeFiles/tracking-itsu-main.dir/build.make
tracking-itsu-main: src/libsrc.a
tracking-itsu-main: /usr/lib64/libOpenCL.so
tracking-itsu-main: CMakeFiles/tracking-itsu-main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fdessena/Desktop/trackCompile/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tracking-itsu-main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tracking-itsu-main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tracking-itsu-main.dir/build: tracking-itsu-main

.PHONY : CMakeFiles/tracking-itsu-main.dir/build

CMakeFiles/tracking-itsu-main.dir/requires: CMakeFiles/tracking-itsu-main.dir/main.cpp.o.requires

.PHONY : CMakeFiles/tracking-itsu-main.dir/requires

CMakeFiles/tracking-itsu-main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tracking-itsu-main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tracking-itsu-main.dir/clean

CMakeFiles/tracking-itsu-main.dir/depend:
	cd /home/fdessena/Desktop/trackCompile/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fdessena/Desktop/trackCompile /home/fdessena/Desktop/trackCompile /home/fdessena/Desktop/trackCompile/build /home/fdessena/Desktop/trackCompile/build /home/fdessena/Desktop/trackCompile/build/CMakeFiles/tracking-itsu-main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tracking-itsu-main.dir/depend

