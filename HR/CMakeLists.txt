cmake_minimum_required(VERSION 3.17)
project(HR)

include_directories(include)

add_executable(binary src/main.cpp src/Employee.cpp src/HRMS.cpp)