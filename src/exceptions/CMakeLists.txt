add_library(exceptions 
    src/exceptions/LackOfAccountFunds.h
    src/exceptions/LackOfAccountFunds.cpp
    src/exceptions/BadCredentials.h
    src/exceptions/BadCredentials.cpp
    src/exceptions/LoginInUse.h
    src/exceptions/LoginInUse.cpp
    src/exceptions/TooManyCards.h
    src/exceptions/TooManyCards.cpp
)

target_include_directories(exceptions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)