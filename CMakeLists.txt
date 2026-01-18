cmake_minimum_required(VERSION 3.16)

project(logicopt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(logicopt
    src/main.cpp
    src/truth_table.cpp
    src/canonical.cpp
)

target_include_directories(logicopt PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Cross-platform warnings (kept simple)
if (MSVC)
  target_compile_options(logicopt PRIVATE /W4)
else()
  target_compile_options(logicopt PRIVATE -Wall -Wextra -Wpedantic)
endif()

