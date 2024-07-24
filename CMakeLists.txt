cmake_minimum_required(VERSION 3.0.2)

project(rk4_custom_practice)

add_compile_options(-std=c++14)

include_directories(
    INCLUDE_DIRS include
)

add_executable(custom_ode_test 
src/custom_ode_test.cpp
include/double_integrator.cpp)

target_link_libraries(custom_ode_test)