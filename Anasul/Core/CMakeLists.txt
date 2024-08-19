
set(ModelName "${PROJECT_NAME}Core")

file(GLOB_RECURSE SOURCES "Sources/*.hpp" "Sources/*.cpp")

add_library(${ModelName} SHARED ${SOURCES})

target_include_directories(${ModelName} PUBLIC "./Sources")

target_precompile_headers(${ModelName} PUBLIC "Sources/Anasul/Config.hpp")

add_custom_command(TARGET ${ModelName}
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different "${PROJECT_SOURCE_DIR}/Anasul/Core/Resources" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Data"
)


