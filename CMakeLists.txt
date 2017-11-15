cmake_minimum_required(VERSION 3.8)
project(Exercise)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        InterviewQuestions/3.FindInPartiallySortedMatrix/FindInPartiallySortedMatrix.cpp
        InterviewQuestions/4.ReplaceBlank/ReplaceBlank.cpp
        InterviewQuestions/5.PrintListInReversedOrder/PrintListInReversedOrder.cpp
        InterviewQuestions/5.PrintListInReversedOrder/PrintListInReversedOrder.h)
add_executable(Exercise ${SOURCE_FILES})