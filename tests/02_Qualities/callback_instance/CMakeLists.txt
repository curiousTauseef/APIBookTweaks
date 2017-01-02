set(EXAMPLE callback_instance)
set(SRC_PATH ${TOP_SRC_PATH}/${EXAMPLE})

include_directories (../../include ${SRC_PATH})

set(sources
   callbackInstanceTest.cpp 
   ${SRC_PATH}/modulea.cpp
   ${SRC_PATH}/moduleb.cpp
)

# Build the executable
add_executable(callbackInstanceTest ${sources})
