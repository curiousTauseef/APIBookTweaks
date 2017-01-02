set(EXAMPLE shared_pointer)
set(SRC_PATH ${TOP_SRC_PATH}/${EXAMPLE})

include_directories (../../include ${SRC_PATH})

set(sources
   sharedPointerTest.cpp 
   ${SRC_PATH}/myobject.cpp)

# Build the executable
add_executable(sharedPointerTest ${sources})
