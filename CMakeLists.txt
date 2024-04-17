cmake_minimum_required(VERSION 3.27)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithms
        AP/ap1.cpp
        implementations/binary_search.c
        implementations/binary_search.cpp
        implementations/merge_sort.cpp
        implementations/merge_sort_skill_issue.c
        implementations/mergesort.c
        implementations/quicksort.cpp)
