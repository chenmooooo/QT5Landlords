cmake_minimum_required(VERSION 3.5)

project(windows)

aux_source_directory(./ SRC)

file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB UIS ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)

add_library(windows ${SRC} ${HEADERS} ${UIS})

target_link_libraries(windows PRIVATE Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Multimedia
)
