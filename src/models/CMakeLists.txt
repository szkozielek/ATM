add_library(models 
    src/models/BankAccount.h
    src/models/BankAccount.cpp
)

target_include_directories(models PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(models ${CM_LIBRARIES})