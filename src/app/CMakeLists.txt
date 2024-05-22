add_library(app 
    src/app/App.cpp
    src/app/App.h
    src/app/Bootstrap.h
)

target_include_directories(app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(app ${CM_LIBRARIES})
target_link_libraries(app controllers)
target_link_libraries(app models)