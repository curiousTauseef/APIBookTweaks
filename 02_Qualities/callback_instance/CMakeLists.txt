# Declare the minimum version of cmake that we need
cmake_minimum_required(VERSION 2.6)

set(sources
   main.cpp modulea.cpp moduleb.cpp) 

# Build the executable
add_executable(callback_instance ${sources})
