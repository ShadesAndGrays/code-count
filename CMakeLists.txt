cmake_minimum_required(VERSION 3.27.0)

project(code-count)

find_package(fmt)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} fmt::fmt)

install(TARGETS ${PROJECT_NAME})
