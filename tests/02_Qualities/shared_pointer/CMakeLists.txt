set(EXAMPLE shared_pointer)
set(SRC_PATH ${TOP_SRC_PATH}/${EXAMPLE})
set(TEST_NAME sharedPointerTest)

include_directories (../../include ${SRC_PATH})

set(sources
   sharedPointerTest.cpp 
   ${SRC_PATH}/myobject.cpp)

# Build the executable
add_executable(${TEST_NAME} ${sources})

add_test(NAME ${TEST_NAME}
    COMMAND ${TEST_NAME} )

