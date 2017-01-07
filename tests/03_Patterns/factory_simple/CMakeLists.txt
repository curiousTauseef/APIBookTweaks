
set(EXAMPLE factory_simple)
set(SRC_PATH ${TOP_SRC_PATH}/${EXAMPLE})
set(TEST_NAME factorySimpleTest)

include_directories (../../include ${SRC_PATH})

set(sources
   factorySimpleTest.cpp
   ${SRC_PATH}/rendererfactory.cpp
)

# Build the executable
add_executable(${TEST_NAME} ${sources})

add_test(NAME ${TEST_NAME}
    COMMAND ${TEST_NAME} )
