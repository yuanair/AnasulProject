
ENABLE_LANGUAGE(ASM_NASM)
set(CMAKE_ASM_NASM_LINK_EXECUTABLE "ld <CMAKE_ASM_NASM_LINK_FLAGS> <LINK_FLAGS> <OBJECTS>  -o <TARGET> <LINK_LIBRARIES>")
set(CMAKE_ASM_NASM_OBJECT_FORMAT elf64)

set(ModelName "ASMTest")

file(GLOB_RECURSE SOURCES "Sources/*.hpp" "Sources/*.cpp" "Sources/*.h" "Sources/*.c" "Sources/*.nasm")

add_executable(${ModelName} ${SOURCES})
set_target_properties(${ModelName} PROPERTIES NASM_OBJ_FORMAT elf64)

target_include_directories(${ModelName} PUBLIC "./Sources")

target_link_libraries(${ModelName} PUBLIC ${PROJECT_NAME}Core PUBLIC ${PROJECT_NAME}Render)

add_custom_command(TARGET ${ModelName}
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different "${CMAKE_CURRENT_SOURCE_DIR}/Resources" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Data"
)
