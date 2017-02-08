
set(EXAMPLE adapter)
set(SRC_PATH ${TOP_SRC_PATH}/${EXAMPLE})
set(TEST_NAME adapterTest)

include_directories (../../include ${SRC_PATH})

set(sources
   adapterTest.cpp
   ${SRC_PATH}/adapter.cpp 
   ${SRC_PATH}/original.cpp
)

# Build the executable
add_executable(${TEST_NAME} ${sources})

add_test(NAME ${TEST_NAME}
    COMMAND ${TEST_NAME} )
