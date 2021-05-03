cmake_minimum_required(VERSION 3.13)
# Project information
project(GlobalDefs
  VERSION 2.0.0
  DESCRIPTION "Common definitions used across multiple libraries"
  LANGUAGES CXX
)
# Add the library target
add_library(global_defs INTERFACE)
# Setup include directories 
target_include_directories(global_defs INTERFACE include/)
