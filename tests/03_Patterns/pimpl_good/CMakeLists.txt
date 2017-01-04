
set(EXAMPLE pimpl_good)
set(SRC_PATH ${TOP_SRC_PATH}/${EXAMPLE})
set(TEST_NAME pimplGoodTest)

include_directories (../../include ${SRC_PATH})

set(sources
   pimplGoodTest.cpp 
   ${SRC_PATH}/autotimer.cpp)

# Build the executable
add_executable(${TEST_NAME} ${sources})

add_test(NAME ${TEST_NAME}
    COMMAND ${TEST_NAME} )
