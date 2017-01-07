
set(EXAMPLE virtDestructor)
set(SRC_PATH ${TOP_SRC_PATH}/${EXAMPLE})
set(TEST_NAME virtDestructorTest)

include_directories (../../include ${SRC_PATH})

set(sources
   virtDestructorTest.cpp 
   )

# Build the executable
add_executable(${TEST_NAME} ${sources})

add_test(NAME ${TEST_NAME}
    COMMAND ${TEST_NAME} )
