# Declare the minimum version of cmake that we need
cmake_minimum_required(VERSION 2.6)

# Setup the name for this CMake project
project(APIBook)

add_definitions(-std=c++14)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

enable_testing()

#Subdirdirectories to build
add_subdirectory(02_Qualities)
add_subdirectory(03_Patterns)

# add tests (should only exist on tests branch)
add_subdirectory(tests)
