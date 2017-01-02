# Declare the minimum version of cmake that we need
cmake_minimum_required(VERSION 2.4)

# Setup the name for this CMake project
project(APIBook)

add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

enable_testing()

#Subdirdirectories to build
add_subdirectory(02_Qualities)

# add tests (should only exist on tests branch)
add_subdirectory(tests)
