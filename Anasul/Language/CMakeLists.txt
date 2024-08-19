
set(ModelName "${PROJECT_NAME}Language")

file(GLOB_RECURSE SOURCES "Sources/*.hpp" "Sources/*.cpp")

add_library(${ModelName} SHARED ${SOURCES})

target_include_directories(${ModelName} PUBLIC "./Sources")

target_link_libraries(${ModelName} PUBLIC "${PROJECT_NAME}Core")

add_custom_command(TARGET ${ModelName}
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different "${CMAKE_CURRENT_SOURCE_DIR}/Resources" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Data"
)

## LLVM
#find_package(LLVM REQUIRED CONFIG)
#message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
#message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
#
#target_include_directories(${ModelName} PUBLIC ${LLVM_INCLUDE_DIRS})
#target_add_definitions(${ModelName} ${LLVM_DEFINITIONS})
#llvm_map_components_to_libnames(llvm_libs support core irreader)
#
## Link against LLVM libraries
#target_link_libraries(${ModelName} PUBLIC ${llvm_libs})
