# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/241/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/241/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/koen/Documents/GitHub/BrowserC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/koen/Documents/GitHub/BrowserC

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target package
package: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool..."
	/snap/clion/241/bin/cmake/linux/x64/bin/cpack --config ./CPackConfig.cmake
.PHONY : package

# Special rule for the target package
package/fast: package
.PHONY : package/fast

# Special rule for the target package_source
package_source:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool for source..."
	/snap/clion/241/bin/cmake/linux/x64/bin/cpack --config ./CPackSourceConfig.cmake /home/koen/Documents/GitHub/BrowserC/CPackSourceConfig.cmake
.PHONY : package_source

# Special rule for the target package_source
package_source/fast: package_source
.PHONY : package_source/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/snap/clion/241/bin/cmake/linux/x64/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/snap/clion/241/bin/cmake/linux/x64/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/snap/clion/241/bin/cmake/linux/x64/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/snap/clion/241/bin/cmake/linux/x64/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/snap/clion/241/bin/cmake/linux/x64/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/snap/clion/241/bin/cmake/linux/x64/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/snap/clion/241/bin/cmake/linux/x64/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/koen/Documents/GitHub/BrowserC/CMakeFiles /home/koen/Documents/GitHub/BrowserC//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/koen/Documents/GitHub/BrowserC/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named MyApp

# Build rule for target.
MyApp: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 MyApp
.PHONY : MyApp

# fast build rule for target.
MyApp/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MyApp.dir/build.make CMakeFiles/MyApp.dir/build
.PHONY : MyApp/fast

#=============================================================================
# Target rules for targets named browser_build

# Build rule for target.
browser_build: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 browser_build
.PHONY : browser_build

# fast build rule for target.
browser_build/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/browser_build.dir/build.make CMakeFiles/browser_build.dir/build
.PHONY : browser_build/fast

#=============================================================================
# Target rules for targets named tidy-static

# Build rule for target.
tidy-static: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 tidy-static
.PHONY : tidy-static

# fast build rule for target.
tidy-static/fast:
	$(MAKE) $(MAKESILENT) -f extern/libtidy/CMakeFiles/tidy-static.dir/build.make extern/libtidy/CMakeFiles/tidy-static.dir/build
.PHONY : tidy-static/fast

#=============================================================================
# Target rules for targets named tidy-share

# Build rule for target.
tidy-share: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 tidy-share
.PHONY : tidy-share

# fast build rule for target.
tidy-share/fast:
	$(MAKE) $(MAKESILENT) -f extern/libtidy/CMakeFiles/tidy-share.dir/build.make extern/libtidy/CMakeFiles/tidy-share.dir/build
.PHONY : tidy-share/fast

#=============================================================================
# Target rules for targets named tidy

# Build rule for target.
tidy: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 tidy
.PHONY : tidy

# fast build rule for target.
tidy/fast:
	$(MAKE) $(MAKESILENT) -f extern/libtidy/CMakeFiles/tidy.dir/build.make extern/libtidy/CMakeFiles/tidy.dir/build
.PHONY : tidy/fast

#=============================================================================
# Target rules for targets named man

# Build rule for target.
man: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 man
.PHONY : man

# fast build rule for target.
man/fast:
	$(MAKE) $(MAKESILENT) -f extern/libtidy/CMakeFiles/man.dir/build.make extern/libtidy/CMakeFiles/man.dir/build
.PHONY : man/fast

#=============================================================================
# Target rules for targets named curl_uninstall

# Build rule for target.
curl_uninstall: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 curl_uninstall
.PHONY : curl_uninstall

# fast build rule for target.
curl_uninstall/fast:
	$(MAKE) $(MAKESILENT) -f extern/curl/CMakeFiles/curl_uninstall.dir/build.make extern/curl/CMakeFiles/curl_uninstall.dir/build
.PHONY : curl_uninstall/fast

#=============================================================================
# Target rules for targets named libcurl

# Build rule for target.
libcurl: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 libcurl
.PHONY : libcurl

# fast build rule for target.
libcurl/fast:
	$(MAKE) $(MAKESILENT) -f extern/curl/lib/CMakeFiles/libcurl.dir/build.make extern/curl/lib/CMakeFiles/libcurl.dir/build
.PHONY : libcurl/fast

#=============================================================================
# Target rules for targets named curl

# Build rule for target.
curl: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 curl
.PHONY : curl

# fast build rule for target.
curl/fast:
	$(MAKE) $(MAKESILENT) -f extern/curl/src/CMakeFiles/curl.dir/build.make extern/curl/src/CMakeFiles/curl.dir/build
.PHONY : curl/fast

#=============================================================================
# Target rules for targets named JavascriptHandler

# Build rule for target.
JavascriptHandler: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 JavascriptHandler
.PHONY : JavascriptHandler

# fast build rule for target.
JavascriptHandler/fast:
	$(MAKE) $(MAKESILENT) -f src/javascript/CMakeFiles/JavascriptHandler.dir/build.make src/javascript/CMakeFiles/JavascriptHandler.dir/build
.PHONY : JavascriptHandler/fast

#=============================================================================
# Target rules for targets named RENDER

# Build rule for target.
RENDER: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 RENDER
.PHONY : RENDER

# fast build rule for target.
RENDER/fast:
	$(MAKE) $(MAKESILENT) -f src/render/CMakeFiles/RENDER.dir/build.make src/render/CMakeFiles/RENDER.dir/build
.PHONY : RENDER/fast

#=============================================================================
# Target rules for targets named AppData

# Build rule for target.
AppData: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 AppData
.PHONY : AppData

# fast build rule for target.
AppData/fast:
	$(MAKE) $(MAKESILENT) -f src/datamanager/CMakeFiles/AppData.dir/build.make src/datamanager/CMakeFiles/AppData.dir/build
.PHONY : AppData/fast

#=============================================================================
# Target rules for targets named TABMANAGER

# Build rule for target.
TABMANAGER: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 TABMANAGER
.PHONY : TABMANAGER

# fast build rule for target.
TABMANAGER/fast:
	$(MAKE) $(MAKESILENT) -f src/tabs/CMakeFiles/TABMANAGER.dir/build.make src/tabs/CMakeFiles/TABMANAGER.dir/build
.PHONY : TABMANAGER/fast

#=============================================================================
# Target rules for targets named TAB

# Build rule for target.
TAB: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 TAB
.PHONY : TAB

# fast build rule for target.
TAB/fast:
	$(MAKE) $(MAKESILENT) -f src/tabs/tab/CMakeFiles/TAB.dir/build.make src/tabs/tab/CMakeFiles/TAB.dir/build
.PHONY : TAB/fast

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MyApp.dir/build.make CMakeFiles/MyApp.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MyApp.dir/build.make CMakeFiles/MyApp.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MyApp.dir/build.make CMakeFiles/MyApp.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... package"
	@echo "... package_source"
	@echo "... rebuild_cache"
	@echo "... browser_build"
	@echo "... curl_uninstall"
	@echo "... man"
	@echo "... AppData"
	@echo "... JavascriptHandler"
	@echo "... MyApp"
	@echo "... RENDER"
	@echo "... TAB"
	@echo "... TABMANAGER"
	@echo "... curl"
	@echo "... libcurl"
	@echo "... tidy"
	@echo "... tidy-share"
	@echo "... tidy-static"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

