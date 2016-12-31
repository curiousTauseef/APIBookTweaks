# Declare the minimum version of cmake that we need
cmake_minimum_required(VERSION 2.6)

set(sources
   main.cpp myobject.cpp)

# Build the executable
add_executable(shared_pointer ${sources})
