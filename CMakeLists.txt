cmake_minimum_required(VERSION 3.27)
project(Anasul)

set(CMAKE_CXX_STANDARD 20)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    add_definitions(-DDEBUG -D_DEBUG)
elseif (${CMAKE_BUILD_TYPE} STREQUAL "Release")

elseif (${CMAKE_BUILD_TYPE} STREQUAL "MinSizeRel")

elseif (${CMAKE_BUILD_TYPE} STREQUAL "RelWithDebInfo")

else ()
    message(FATAL_ERROR "CMAKE_BUILD_TYPE is unknown")
endif ()

# Wall
# add_compile_options(-Wall)

# no exception
# add_compile_options(-fno-exceptions)

# UNICODE
add_definitions(-DUNICODE -D_UNICODE)

# Output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/${CMAKE_CXX_COMPILER_ID}_${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/${CMAKE_CXX_COMPILER_ID}_${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/${CMAKE_CXX_COMPILER_ID}_${CMAKE_BUILD_TYPE})

#
add_executable(Main "main.cpp")
target_link_libraries(Main PUBLIC ${PROJECT_NAME}Core PUBLIC ${PROJECT_NAME}Language)

add_subdirectory(Anasul)
