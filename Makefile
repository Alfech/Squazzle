# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = C:\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\lafle\Desktop\StickWarrior\StickWarrior-vs-The-Tower-of-Pain

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lafle\Desktop\StickWarrior\StickWarrior-vs-The-Tower-of-Pain

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	C:\mingw64\bin\cmake.exe -E echo "No interactive CMake dialog available."
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	C:\mingw64\bin\cmake.exe --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start C:\Users\lafle\Desktop\StickWarrior\StickWarrior-vs-The-Tower-of-Pain\CMakeFiles C:\Users\lafle\Desktop\StickWarrior\StickWarrior-vs-The-Tower-of-Pain\\CMakeFiles\progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start C:\Users\lafle\Desktop\StickWarrior\StickWarrior-vs-The-Tower-of-Pain\CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named The_tower_of_pain

# Build rule for target.
The_tower_of_pain: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 The_tower_of_pain
.PHONY : The_tower_of_pain

# fast build rule for target.
The_tower_of_pain/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\The_tower_of_pain.dir\build.make CMakeFiles/The_tower_of_pain.dir/build
.PHONY : The_tower_of_pain/fast

src/Main.obj: src/Main.cpp.obj
.PHONY : src/Main.obj

# target to build an object file
src/Main.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\The_tower_of_pain.dir\build.make CMakeFiles/The_tower_of_pain.dir/src/Main.cpp.obj
.PHONY : src/Main.cpp.obj

src/Main.i: src/Main.cpp.i
.PHONY : src/Main.i

# target to preprocess a source file
src/Main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\The_tower_of_pain.dir\build.make CMakeFiles/The_tower_of_pain.dir/src/Main.cpp.i
.PHONY : src/Main.cpp.i

src/Main.s: src/Main.cpp.s
.PHONY : src/Main.s

# target to generate assembly for a file
src/Main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\The_tower_of_pain.dir\build.make CMakeFiles/The_tower_of_pain.dir/src/Main.cpp.s
.PHONY : src/Main.cpp.s

src/core/Game.obj: src/core/Game.cpp.obj
.PHONY : src/core/Game.obj

# target to build an object file
src/core/Game.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\The_tower_of_pain.dir\build.make CMakeFiles/The_tower_of_pain.dir/src/core/Game.cpp.obj
.PHONY : src/core/Game.cpp.obj

src/core/Game.i: src/core/Game.cpp.i
.PHONY : src/core/Game.i

# target to preprocess a source file
src/core/Game.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\The_tower_of_pain.dir\build.make CMakeFiles/The_tower_of_pain.dir/src/core/Game.cpp.i
.PHONY : src/core/Game.cpp.i

src/core/Game.s: src/core/Game.cpp.s
.PHONY : src/core/Game.s

# target to generate assembly for a file
src/core/Game.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\The_tower_of_pain.dir\build.make CMakeFiles/The_tower_of_pain.dir/src/core/Game.cpp.s
.PHONY : src/core/Game.cpp.s

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... edit_cache
	@echo ... rebuild_cache
	@echo ... The_tower_of_pain
	@echo ... src/Main.obj
	@echo ... src/Main.i
	@echo ... src/Main.s
	@echo ... src/core/Game.obj
	@echo ... src/core/Game.i
	@echo ... src/core/Game.s
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system
