add_library(models 
    src/models/BankAccount.h
    src/models/BankAccount.cpp
    src/models/ATM.h
    src/models/ATM.cpp
    src/models/DebitCard.h
    src/models/DebitCard.cpp
    src/models/BankAccountBallance.h
    src/models/BankAccountBallance.cpp
)

target_include_directories(models PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(models ${CM_LIBRARIES})