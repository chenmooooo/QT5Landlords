cmake_minimum_required(VERSION 3.5)

project(control)

aux_source_directory(./ SRC)

file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB UIS ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)

add_library(control ${SRC} ${HEADERS} ${UIS})

target_link_libraries(control PRIVATE Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Multimedia

)
