# Declare the minimum version of cmake that we need
cmake_minimum_required(VERSION 2.6)

add_definitions(-std=c++14)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

# Specify the subdirectories to build
add_subdirectory(pimpl_good)
add_subdirectory(singleton)
add_subdirectory(virtDestructor)
add_subdirectory(factory_simple)
add_subdirectory(factory_extensible)
add_subdirectory(adapter)

