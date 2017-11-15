cmake_minimum_required(VERSION 3.8)
project(Exercise)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c
        InterviewQuestions/3.FindInPartiallySortedMatrix/FindInPartiallySortedMatrix.cpp)
add_executable(Exercise ${SOURCE_FILES})