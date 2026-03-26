cmake_minimum_required(VERSION 3.14)
project(Lab_LinkedList)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Створюємо бібліотеку (це наш основний код БЕЗ main)
add_library(ListLib list.cpp list.h)

# 2. Основний додаток (для демонстрації викладачу)
add_executable(MainApp main.cpp)
target_link_libraries(MainApp ListLib)

# 3. Підключення Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 4. Тестовий додаток
enable_testing()
add_executable(UnitTest UnitTest.cpp)

# ВАЖЛИВО: додаємо gtest_main, він замінює main() у тестах
target_link_libraries(UnitTest ListLib gtest gtest_main)

# Резервний спосіб реєстрації тестів
add_test(NAME AllTests COMMAND UnitTest)