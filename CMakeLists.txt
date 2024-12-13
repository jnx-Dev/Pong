cmake_minimum_required(VERSION 3.26)

project(Pong VERSION 0.0)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
	add_compile_options( /W4 /WX-)
else()
	add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

find_package(SDL3 CONFIG REQUIRED)

add_executable(Pong src/main.cpp src/Application.cpp src/Paddle.cpp src/Ball.cpp)

target_link_libraries(Pong PRIVATE SDL3::SDL3)
