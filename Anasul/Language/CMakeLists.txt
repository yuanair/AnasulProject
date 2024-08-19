
set(ModelName "${PROJECT_NAME}Language")

file(GLOB_RECURSE SOURCES "Sources/*.hpp" "Sources/*.cpp")

add_library(${ModelName} SHARED ${SOURCES})

target_include_directories(${ModelName} PUBLIC "./Sources")

target_link_libraries(${ModelName} PUBLIC "${PROJECT_NAME}Core")

