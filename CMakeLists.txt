cmake_minimum_required(VERSION 3.0.0)

set(CM_PROJECT_NAME
    CashMachine
)
set(CM_SOURCE_DIR
    src
)
set(CM_SOURCE
    ${CM_SOURCE_DIR}/main.cpp
)
set(CM_LIBRARIES_DIR
    libs
)
set(CM_LIBRARIES 
    Kernel
    Menu
    FileManager
    GetEnv
    SmartString
)

project(${CM_PROJECT_NAME})

#########
# GTest #
#########
# enable_testing()
# add_subdirectory(libs/gtest-1.7.0)
# include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

###########
# Project #
###########
add_executable(${CM_PROJECT_NAME} ${CM_SOURCE})

foreach(LIBRARY ${CM_LIBRARIES})
    add_subdirectory("${CM_LIBRARIES_DIR}/${LIBRARY}")
endforeach(LIBRARY)

target_link_libraries(${CM_PROJECT_NAME} ${CM_LIBRARIES})

configure_file(.env.example .env)
configure_file(bank_accounts.txt bank_accounts.txt)