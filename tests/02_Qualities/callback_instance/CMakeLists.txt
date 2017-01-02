set(EXAMPLE callback_instance)
set(SRC_PATH ${TOP_SRC_PATH}/${EXAMPLE})
set(TEST_NAME callbackInstanceTest)

include_directories (../../include ${SRC_PATH})

set(sources
   callbackInstanceTest.cpp 
   ${SRC_PATH}/modulea.cpp
   ${SRC_PATH}/moduleb.cpp
)

# Build the executable
add_executable(${TEST_NAME} ${sources})

add_test(NAME ${TEST_NAME}
    COMMAND ${TEST_NAME} )
