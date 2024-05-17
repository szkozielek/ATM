
cmake_minimum_required(VERSION 3.5.0)

set(PROJECT_NAME
    ChangeMakingLibrary
)
set(LIBRARY_NAME
    ChangeMaking
)
set(LIBRARY_HEADERS_DIR
    include/${LIBRARY_NAME}
)
set(LIBRARY_HEADERS
    ${LIBRARY_HEADERS_DIR}/ChangeMaking.h
    #exceptions
    ${LIBRARY_HEADERS_DIR}/TooLargeAmount.h
    ${LIBRARY_HEADERS_DIR}/ImpossibleToChange.h
)
set(LIBRARY_SOURCE_DIR
    src
)
set(LIBRARY_SOURCE
    ${LIBRARY_SOURCE_DIR}/ChangeMaking.cpp
    #exceptions
    ${LIBRARY_SOURCE_DIR}/TooLargeAmount.cpp
    ${LIBRARY_SOURCE_DIR}/ImpossibleToChange.cpp
)

project(${PROJECT_NAME})

add_library(${LIBRARY_NAME} STATIC
    ${LIBRARY_HEADERS}
    ${LIBRARY_SOURCE}
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
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