set(CHAPTER 03_Patterns)
set(TOP_SRC_PATH ${PROJECT_SOURCE_DIR}/${CHAPTER})

# add tests (should only exist on tests branch)
add_subdirectory(pimpl_good)
add_subdirectory(singleton)
add_subdirectory(virtDestructor)
add_subdirectory(factory_simple)
add_subdirectory(factory_extensible)
add_subdirectory(adapter)

