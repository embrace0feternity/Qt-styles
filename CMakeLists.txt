cmake_minimum_required(VERSION 3.16)

include(cmake_utils/modules.cmake)
include(cmake_utils/generate_execution.cmake)
include(cmake_utils/debug.cmake)

project(styles VERSION 0.1 LANGUAGES CXX)

message("Cmake run\n")

set(check 1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

message(STATUS "Cmake cxx standard: ${CMAKE_CXX_STANDARD}")

find_package(QT NAMES Qt6 Qt5 COMPONENTS Test Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Test Widgets REQUIRED)

set(STYLES_NAME style)

set(STYLES_SRCS
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        style_list_widget.cpp
        style_list_widget.hpp
)

generateExecution(${STYLES_NAME}
    srcs ${STYLES_SRCS}
    libs Qt${QT_VERSION_MAJOR}::Widgets
    wErr wAll
    )


set(STYLES_TEST styles_test)
set(STYLES_TEST_SRCS
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/styleListWidget/main.cpp
    )

generateExecution(${STYLES_TEST}
    srcs ${STYLES_TEST_SRCS}
    libs Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Test
    wErr wAll)
