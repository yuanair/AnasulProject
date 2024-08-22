
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    set(CMAKE_PREFIX_PATH "C:/Qt/6.7.2/mingw_64")
    message(WARNING "compiler: mingw_64")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
    set(CMAKE_PREFIX_PATH "C:/Qt/6.7.2/llvm-mingw_64")
    message(WARNING "compiler: llvm-mingw_64")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    set(CMAKE_PREFIX_PATH "C:/Qt/6.7.2/msvc2019_64")
    message(WARNING "compiler: msvc2019_64")
else ()
    message(FATAL_ERROR "Unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")
endif ()

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(ModelName "${PROJECT_NAME}Qt")

file(GLOB_RECURSE SOURCES "Sources/*.hpp" "Sources/*.cpp")

add_library(${ModelName} STATIC ${SOURCES})

target_include_directories(${ModelName} PUBLIC "./Sources")

target_link_libraries(${ModelName}
        PUBLIC "${PROJECT_NAME}Core"
        PUBLIC Qt::Core
        PUBLIC Qt::Gui
        PUBLIC Qt::Widgets)

add_custom_command(TARGET ${ModelName}
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different "${CMAKE_CURRENT_SOURCE_DIR}/Resources" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Data"
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${ModelName} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${ModelName}>/plugins/platforms/")
        add_custom_command(TARGET ${ModelName} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${ModelName}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${ModelName} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${ModelName}>")
    endforeach (QT_LIB)
endif ()

