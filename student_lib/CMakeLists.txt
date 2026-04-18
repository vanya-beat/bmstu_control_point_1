project(student_lib C CXX)
add_library(student_lib STATIC
    student_tasks.c
    student_tasks.cpp
)

target_include_directories(student_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(student_lib PROPERTIES LINKER_LANGUAGE CXX)
