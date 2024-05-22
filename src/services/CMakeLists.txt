add_library(services 
    src/services/LoginService.h
    src/services/LoginService.cpp
)

target_include_directories(services PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)