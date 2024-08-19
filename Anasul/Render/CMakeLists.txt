
set(ModelName "${PROJECT_NAME}Render")

file(GLOB_RECURSE SOURCES "Sources/*.hpp" "Sources/*.cpp")

add_library(${ModelName} SHARED ${SOURCES})

target_include_directories(${ModelName} PUBLIC "./Sources")

target_link_libraries(${ModelName} PUBLIC "${PROJECT_NAME}Core")

add_custom_command(TARGET ${ModelName}
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different "${CMAKE_CURRENT_SOURCE_DIR}/Resources" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Data"
)