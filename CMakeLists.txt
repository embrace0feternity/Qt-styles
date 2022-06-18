cmake_minimum_required(VERSION 3.16)

project(styles VERSION 0.1 LANGUAGES CXX)

message("Cmake run")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

message(STATUS "Cmake cxx standard: ${CMAKE_CXX_STANDARD}")

find_package(QT NAMES Qt6 Qt5 COMPONENTS Test Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Test Widgets REQUIRED)

set(STYLES_NAME styles)
set(STYLES_SRCS
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        style_list_widget.cpp
        style_list_widget.hpp
)

add_executable(${STYLES_NAME}
    ${STYLES_SRCS}
)

target_link_libraries(${STYLES_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)


set(STYLES_TEST styles_test)
set(STYLES_TEST_SRCS
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/styleListWidget/main.cpp
    )

add_executable(${STYLES_TEST}
    ${STYLES_TEST_SRCS})

target_link_libraries(${STYLES_TEST} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Test)

set_target_properties(${STYLES_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)
