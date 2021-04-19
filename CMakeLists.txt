cmake_minimum_required(VERSION 3.13)
# Project information
project(GlobalDefs
  VERSION 1.0.0
  DESCRIPTION "Common definitions used across multiple libraries"
  LANGUAGES CXX
)
# Add the library target
add_library(global_defs INTERFACE)
# Setup include directories 
target_include_directories(global_defs INTERFACE include/)

# Example and unit testing if this project is built separately
if (PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
	# Add the example target
	add_executable(global_defs_ex examples/global_defs_ex.cc)
	# Add the includes
	target_include_directories(global_defs_ex PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	)
	# Link libraries to the test target
	target_link_libraries(global_defs_ex
		PRIVATE
			global_defs
	)
endif()
