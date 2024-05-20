add_library(layout 
    src/layout/Layout.h
    src/layout/Cover.h
    src/layout/Exit.h
    src/layout/Select.h
    src/layout/ValidateError.h
)
set_target_properties(layout PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(layout PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)