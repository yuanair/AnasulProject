
set(ModelName "${PROJECT_NAME}Render")

file(GLOB_RECURSE SOURCES "Sources/*.hpp" "Sources/*.cpp")

add_library(${ModelName} SHARED ${SOURCES})

target_include_directories(${ModelName} PUBLIC "./Sources" PUBLIC "${PROJECT_SOURCE_DIR}/glfw/include")

target_link_libraries(${ModelName} PUBLIC "${PROJECT_NAME}Core" PUBLIC GLAD
        PUBLIC "${PROJECT_SOURCE_DIR}/glfw/lib-vc2022/glfw3dll.lib"
        PUBLIC opengl32.lib
        PUBLIC Dwmapi.lib
        PUBLIC imm32.lib)

add_custom_command(TARGET ${ModelName}
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different "${CMAKE_CURRENT_SOURCE_DIR}/Resources" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Data"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PROJECT_SOURCE_DIR}/glfw/lib-vc2022/glfw3.dll" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)

# Vulkan
#find_package(Vulkan REQUIRED)
#target_include_directories(${ModelName} PUBLIC ${Vulkan_INCLUDE_DIRS})
#target_link_libraries(${ModelName} Vulkan::Vulkan)
