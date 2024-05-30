add_library(bootstrap 
    src/bootstrap/App.cpp
    src/bootstrap/App.h
    src/bootstrap/Init.h
)

target_include_directories(bootstrap PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(bootstrap ${CM_LIBRARIES})
target_link_libraries(bootstrap controllers)
target_link_libraries(bootstrap models)