# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lusubu/EntropyCalculator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lusubu/EntropyCalculator/try99

# Include any dependencies generated for this target.
include CMakeFiles/EntropyCalculator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/EntropyCalculator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/EntropyCalculator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EntropyCalculator.dir/flags.make

ui_mainwindow.h: ../mainwindow.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lusubu/EntropyCalculator/try99/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ui_mainwindow.h"
	/usr/lib/qt5/bin/uic -o /home/lusubu/EntropyCalculator/try99/ui_mainwindow.h /home/lusubu/EntropyCalculator/mainwindow.ui

CMakeFiles/EntropyCalculator.dir/EntropyCalculator_autogen/mocs_compilation.cpp.o: CMakeFiles/EntropyCalculator.dir/flags.make
CMakeFiles/EntropyCalculator.dir/EntropyCalculator_autogen/mocs_compilation.cpp.o: EntropyCalculator_autogen/mocs_compilation.cpp
CMakeFiles/EntropyCalculator.dir/EntropyCalculator_autogen/mocs_compilation.cpp.o: CMakeFiles/EntropyCalculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lusubu/EntropyCalculator/try99/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/EntropyCalculator.dir/EntropyCalculator_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EntropyCalculator.dir/EntropyCalculator_autogen/mocs_compilation.cpp.o -MF CMakeFiles/EntropyCalculator.dir/EntropyCalculator_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/EntropyCalculator.dir/EntropyCalculator_autogen/mocs_compilation.cpp.o -c /home/lusubu/EntropyCalculator/try99/EntropyCalculator_autogen/mocs_compilation.cpp

CMakeFiles/EntropyCalculator.dir/EntropyCalculator_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EntropyCalculator.dir/EntropyCalculator_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lusubu/EntropyCalculator/try99/EntropyCalculator_autogen/mocs_compilation.cpp > CMakeFiles/EntropyCalculator.dir/EntropyCalculator_autogen/mocs_compilation.cpp.i

CMakeFiles/EntropyCalculator.dir/EntropyCalculator_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EntropyCalculator.dir/EntropyCalculator_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lusubu/EntropyCalculator/try99/EntropyCalculator_autogen/mocs_compilation.cpp -o CMakeFiles/EntropyCalculator.dir/EntropyCalculator_autogen/mocs_compilation.cpp.s

CMakeFiles/EntropyCalculator.dir/main.cpp.o: CMakeFiles/EntropyCalculator.dir/flags.make
CMakeFiles/EntropyCalculator.dir/main.cpp.o: ../main.cpp
CMakeFiles/EntropyCalculator.dir/main.cpp.o: CMakeFiles/EntropyCalculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lusubu/EntropyCalculator/try99/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/EntropyCalculator.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EntropyCalculator.dir/main.cpp.o -MF CMakeFiles/EntropyCalculator.dir/main.cpp.o.d -o CMakeFiles/EntropyCalculator.dir/main.cpp.o -c /home/lusubu/EntropyCalculator/main.cpp

CMakeFiles/EntropyCalculator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EntropyCalculator.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lusubu/EntropyCalculator/main.cpp > CMakeFiles/EntropyCalculator.dir/main.cpp.i

CMakeFiles/EntropyCalculator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EntropyCalculator.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lusubu/EntropyCalculator/main.cpp -o CMakeFiles/EntropyCalculator.dir/main.cpp.s

CMakeFiles/EntropyCalculator.dir/mainwindow.cpp.o: CMakeFiles/EntropyCalculator.dir/flags.make
CMakeFiles/EntropyCalculator.dir/mainwindow.cpp.o: ../mainwindow.cpp
CMakeFiles/EntropyCalculator.dir/mainwindow.cpp.o: CMakeFiles/EntropyCalculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lusubu/EntropyCalculator/try99/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/EntropyCalculator.dir/mainwindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EntropyCalculator.dir/mainwindow.cpp.o -MF CMakeFiles/EntropyCalculator.dir/mainwindow.cpp.o.d -o CMakeFiles/EntropyCalculator.dir/mainwindow.cpp.o -c /home/lusubu/EntropyCalculator/mainwindow.cpp

CMakeFiles/EntropyCalculator.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EntropyCalculator.dir/mainwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lusubu/EntropyCalculator/mainwindow.cpp > CMakeFiles/EntropyCalculator.dir/mainwindow.cpp.i

CMakeFiles/EntropyCalculator.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EntropyCalculator.dir/mainwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lusubu/EntropyCalculator/mainwindow.cpp -o CMakeFiles/EntropyCalculator.dir/mainwindow.cpp.s

CMakeFiles/EntropyCalculator.dir/raddix.cpp.o: CMakeFiles/EntropyCalculator.dir/flags.make
CMakeFiles/EntropyCalculator.dir/raddix.cpp.o: ../raddix.cpp
CMakeFiles/EntropyCalculator.dir/raddix.cpp.o: CMakeFiles/EntropyCalculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lusubu/EntropyCalculator/try99/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/EntropyCalculator.dir/raddix.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/EntropyCalculator.dir/raddix.cpp.o -MF CMakeFiles/EntropyCalculator.dir/raddix.cpp.o.d -o CMakeFiles/EntropyCalculator.dir/raddix.cpp.o -c /home/lusubu/EntropyCalculator/raddix.cpp

CMakeFiles/EntropyCalculator.dir/raddix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EntropyCalculator.dir/raddix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lusubu/EntropyCalculator/raddix.cpp > CMakeFiles/EntropyCalculator.dir/raddix.cpp.i

CMakeFiles/EntropyCalculator.dir/raddix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EntropyCalculator.dir/raddix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lusubu/EntropyCalculator/raddix.cpp -o CMakeFiles/EntropyCalculator.dir/raddix.cpp.s

# Object files for target EntropyCalculator
EntropyCalculator_OBJECTS = \
"CMakeFiles/EntropyCalculator.dir/EntropyCalculator_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/EntropyCalculator.dir/main.cpp.o" \
"CMakeFiles/EntropyCalculator.dir/mainwindow.cpp.o" \
"CMakeFiles/EntropyCalculator.dir/raddix.cpp.o"

# External object files for target EntropyCalculator
EntropyCalculator_EXTERNAL_OBJECTS =

EntropyCalculator: CMakeFiles/EntropyCalculator.dir/EntropyCalculator_autogen/mocs_compilation.cpp.o
EntropyCalculator: CMakeFiles/EntropyCalculator.dir/main.cpp.o
EntropyCalculator: CMakeFiles/EntropyCalculator.dir/mainwindow.cpp.o
EntropyCalculator: CMakeFiles/EntropyCalculator.dir/raddix.cpp.o
EntropyCalculator: CMakeFiles/EntropyCalculator.dir/build.make
EntropyCalculator: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
EntropyCalculator: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
EntropyCalculator: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
EntropyCalculator: CMakeFiles/EntropyCalculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lusubu/EntropyCalculator/try99/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable EntropyCalculator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EntropyCalculator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EntropyCalculator.dir/build: EntropyCalculator
.PHONY : CMakeFiles/EntropyCalculator.dir/build

CMakeFiles/EntropyCalculator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EntropyCalculator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EntropyCalculator.dir/clean

CMakeFiles/EntropyCalculator.dir/depend: ui_mainwindow.h
	cd /home/lusubu/EntropyCalculator/try99 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lusubu/EntropyCalculator /home/lusubu/EntropyCalculator /home/lusubu/EntropyCalculator/try99 /home/lusubu/EntropyCalculator/try99 /home/lusubu/EntropyCalculator/try99/CMakeFiles/EntropyCalculator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EntropyCalculator.dir/depend

