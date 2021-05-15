cmake_minimum_required(VERSION 3.17)
project(IntegrationInterpolation)

set(CMAKE_CXX_STANDARD 14)

add_executable(IntegrationInterpolation Point.h Point.cpp Integration_Scheme.h Integration_Scheme_Interval.cpp
               Integration_Scheme_Interval.h Lesson4_Integration.cpp )