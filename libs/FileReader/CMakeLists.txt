
cmake_minimum_required(VERSION 3.0.0)

set(PROJECT_NAME
    FileReaderLibrary
)

set(LIBRARY_NAME
    FileReader
)

set(LIBRARY_HEADERS_DIR
    include/${LIBRARY_NAME}
)

set(LIBRARY_HEADERS
    ${LIBRARY_HEADERS_DIR}/FileReader.h
    # exceptions
    ${LIBRARY_HEADERS_DIR}/FileNotFound.h
    ${LIBRARY_HEADERS_DIR}/FileNotReadable.h
)

set(LIBRARY_SOURCE_DIR
    src
)

set(LIBRARY_SOURCE
    ${LIBRARY_SOURCE_DIR}/FileReader.cpp
    # exceptions
    ${LIBRARY_SOURCE_DIR}/FileNotFound.cpp
    ${LIBRARY_SOURCE_DIR}/FileNotReadable.cpp
)

project(${PROJECT_NAME})

add_library(${LIBRARY_NAME} STATIC
    ${LIBRARY_HEADERS}
    ${LIBRARY_SOURCE}
)

target_include_directories(${LIBRARY_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}>
    $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>
)

target_include_directories(${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# add_subdirectory(test)