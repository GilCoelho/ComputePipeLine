project(CPL_MAIN)

add_subdirectory(Loader)
add_subdirectory(Actions)
add_subdirectory(ComputePipeline)

set(SOURCES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        CPL::Loader
        CPL::Actions
        CPL::ComputePileLine
)
