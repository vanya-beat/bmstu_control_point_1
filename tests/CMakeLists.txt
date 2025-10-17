# Создаем исполняемый файл с тестами (C++ для Google Test)
add_executable(student_tests
    test_student_tasks.cpp
    custom_main.cpp
)

# Линкуем библиотеки (убираем gtest_main, используем свой main)
target_link_libraries(student_tests
    student_lib
    GTest::gtest
)

# Добавляем include директорию для score_calculator.h
target_include_directories(student_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Добавляем тесты в CTest
include(GoogleTest)
gtest_discover_tests(student_tests)
