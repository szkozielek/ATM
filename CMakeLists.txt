cmake_minimum_required(VERSION 3.5.0)

set(CM_PROJECT_NAME
    ATM
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
    ChangeMaking
    Hash
)
set(CM_PROJECT_LIBS
    bootstrap
    controllers
    layout
    models
    views
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

foreach(LIBRARY ${CM_PROJECT_LIBS})
    add_subdirectory("${CM_SOURCE_DIR}/${LIBRARY}")
endforeach(LIBRARY)

target_link_libraries(${CM_PROJECT_NAME} ${CM_PROJECT_LIBS})

target_link_libraries(${CM_PROJECT_NAME} ${CM_LIBRARIES})


set(CM_ACCOUNT_DIR bank)
set(CM_ACCOUNT_FILE bank_accounts.txt)
set(CM_DEBIT_CARD_DIR bank)
set(CM_DEBIT_CARD_FILE debit_cards.txt)
set(CM_ATM_DIR cashbox)
set(CM_ATM_DEFAULT_KEY f1b4c587-f9f6-4f0c-b6f2-321a51e41789)
set(CM_BALANCE_DIR bank)
set(CM_CURRENCIES
    PLN
    EUR
    USD
    CHF
    GBP
    JPY
)


configure_file(.env.example .env @ONLY)

configure_file(resources/bank_accounts.txt ${CM_ACCOUNT_DIR}/${CM_ACCOUNT_FILE})
configure_file(resources/debit_cards.txt ${CM_DEBIT_CARD_DIR}/${CM_DEBIT_CARD_FILE})

foreach(CM_CURRENCY ${CM_CURRENCIES})
    configure_file(resources/currency.txt ${CM_BALANCE_DIR}/${CM_CURRENCY}.txt)
    # configure_file(resources/cashbox.txt ${CM_ATM_DIR}/${CM_CURRENCY}.txt)
endforeach(CM_CURRENCY)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CM_ATM_DIR})