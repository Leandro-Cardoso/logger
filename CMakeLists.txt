cmake_minimum_required(VERSION 3.10)
project(Logger
    VERSION 1.0.0
    DESCRIPTION "Log Library"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# =========================
# Biblioteca
# =========================
add_library(Logger
    src/A.cpp
)

# INCLUDE HEADERS:
target_include_directories(Logger
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# =========================
# Examples
# =========================
add_executable(a_example examples/a_example.cpp)
target_link_libraries(a_example PRIVATE Logger)

# =========================
# Tests
# =========================
enable_testing()

# GOOGLE TEST:
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# EXECUTABLES:
add_executable(tests
    tests/ATests.cpp
)

# LINK LIBRARIES:
target_link_libraries(tests
    PRIVATE
        Logger
        gtest
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)

# BUILD INSTRUCTIONS:
# cmake -S . -B build -G "MinGW Makefiles"
# cmake --build build
