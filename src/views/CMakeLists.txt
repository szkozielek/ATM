add_library(views
    src/views/View.h
    src/views/View.cpp
    src/views/SelectOptionView.h
    src/views/SelectOptionView.cpp
    src/views/PasswordView.h
    src/views/PasswordView.cpp
    src/views/NewCardIDView.h
    src/views/NewCardIDView.cpp
    src/views/InputView.h
    src/views/MarkView.h
    src/views/CollectMoneyView.h
    src/views/CollectMoneyView.cpp
    src/views/InsertCashView.h
    src/views/InsertCashView.cpp
    src/views/ConfirmView.h
    src/views/ConfirmView.cpp
    src/views/ErrorView.h
    src/views/ErrorView.cpp
    src/views/CoverView.h
    src/views/CoverView.cpp
    src/views/SectionHeaderView.h
    src/views/SectionHeaderView.cpp
    src/views/MyCardIDsView.h
    src/views/MyCardIDsView.cpp
    src/views/BallanceView.h
    src/views/BallanceView.cpp
)

target_include_directories(views PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(views ${CM_LIBRARIES})
target_link_libraries(views layout)