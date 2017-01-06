
set(EXAMPLE singleton)
set(SRC_PATH ${TOP_SRC_PATH}/${EXAMPLE})
set(TEST_NAME singletonTest)
set(TMP_COMP_FILE ${TEST_NAME}_capture.txt)
set(APPROVED_COMP_FILE approvedCapture.txt)

include_directories (../../include ${SRC_PATH})

set(sources
   singletonTest.cpp 
   ${SRC_PATH}/singleton.cpp)

# Build the executable
add_executable(${TEST_NAME} ${sources})

# After test built, run and redirect stdout to file to test against
add_custom_command(
   TARGET ${TEST_NAME}
   POST_BUILD
   DEPENDS ${TEST_NAME}
   COMMAND ${CMAKE_COMMAND} -E echo “Running $<TARGET_FILE:${TEST_NAME}> …”
   COMMAND $<TARGET_FILE:${TEST_NAME}> > ${CMAKE_CURRENT_BINARY_DIR}/${TMP_COMP_FILE}
   USES_TERMINAL
)

#compare the approved file with the output file that was generated in the POST_BUILD
add_test(
    NAME ${TEST_NAME}_1
    COMMAND ${CMAKE_COMMAND} -E compare_files ${CMAKE_CURRENT_BINARY_DIR}/${TMP_COMP_FILE} ${CMAKE_CURRENT_SOURCE_DIR}/${APPROVED_COMP_FILE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
