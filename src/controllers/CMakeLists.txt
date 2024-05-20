add_library(controllers 
    src/controllers/Controller.cpp
    src/controllers/Controller.h
    src/controllers/StartController.cpp
    src/controllers/StartController.h
    src/controllers/BankAccountController.cpp
    src/controllers/BankAccountController.h
)

target_include_directories(controllers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(controllers ${CM_LIBRARIES})
target_link_libraries(controllers layout)