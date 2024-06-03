add_library(services 
    src/services/CurrencyService.h
    src/services/CurrencyService.cpp
)

target_include_directories(services PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)