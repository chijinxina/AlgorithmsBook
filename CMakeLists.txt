cmake_minimum_required(VERSION 3.8.2)
project(AlgorithmsBook)

set(CMAKE_CXX_STANDARD 11)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#####################dependenicecs##########################
set(THIRD_PARTY_LIBS
        )
include_directories(${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/多线程/实现WaitGroup
        )
####################source and test#########################
add_subdirectory(src)


# leetcode 136 只出现一次的数字
add_executable(singleNumber1 只出现一次的数字/SingleNumber.cpp)
add_executable(singleNumber2 只出现一次的数字/SingleNumber2.cpp)


# 两个线程交替打印奇偶数
add_executable(twoThreadsPrint 多线程/两个线程交替打印奇偶数/TwoThreadsPrint.cpp)
# 三个线程依次打印零奇偶数
add_executable(threeThreadsPrint 多线程/三个线程依次打印零奇偶数/ThreeThreadsPrint.cpp 多线程/实现WaitGroup/WaitGroup.cpp)


# test
add_executable(test test/test.cpp)

# 链表反转
add_executable(ListReverse 链表反转/list_reverse.cpp)

