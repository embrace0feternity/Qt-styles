cmake_minimum_required(VERSION 3.16)

include(cmake_utils/modules.cmake)
include(cmake_utils/generate_execution.cmake)
include(cmake_utils/debug.cmake)

project(styles VERSION 0.1 LANGUAGES CXX)

enable_testing()

message("Cmake run\n")

set(check 1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

configure_file(style_list_widget.qss ${CMAKE_CURRENT_BINARY_DIR}/style_list_widget.qss COPYONLY)

message(STATUS "Cmake cxx standard: ${CMAKE_CXX_STANDARD}")

find_package(QT NAMES Qt6 COMPONENTS Test Widgets REQUIRED)
find_package(Qt6 COMPONENTS Test Widgets REQUIRED)

message("QT_VERSION_MAJOR = ${QT_VERSION_MAJOR}")

set(STYLES_NAME style)

set(STYLES_SRCS
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        style_list_widget.hpp
        ${CMAKE_CURRENT_BINARY_DIR}/style_list_widget.qss
        style_list_widget.cpp
)

generateExecution(${STYLES_NAME}
    srcs ${STYLES_SRCS}
    libs Qt6::Widgets
    )

set(STYLES_TEST styles_test)
set(STYLES_TEST_SRCS

    style_list_widget.hpp
    style_list_widget.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/style_list_widget.qss
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/list_widget/list_widget.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/list_widget/wrapper.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/list_widget/wrapper.hpp
    )

message("CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}S")

generateExecution(${STYLES_TEST}
    srcs ${STYLES_TEST_SRCS}
    libs Qt6::Widgets Qt6::Test
    )

add_test(NAME ${STYLES_TEST}
         COMMAND ${STYLES_TEST})




