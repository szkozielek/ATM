add_library(controllers 
    src/controllers/Controller.cpp
    src/controllers/Controller.h
    src/controllers/StartController.cpp
    src/controllers/StartController.h
    src/controllers/ATMController.cpp
    src/controllers/ATMController.h
    src/controllers/BankController.cpp
    src/controllers/BankController.h
    src/controllers/BankAccountController.cpp
    src/controllers/BankAccountController.h
    src/controllers/CardController.cpp
    src/controllers/CardController.h
)

target_include_directories(controllers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(controllers ${CM_LIBRARIES})
target_link_libraries(controllers layout)
target_link_libraries(controllers views)
target_link_libraries(controllers models)
target_link_libraries(controllers services)
target_link_libraries(controllers exceptions)