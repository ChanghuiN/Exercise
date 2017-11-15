cmake_minimum_required(VERSION 3.8)
project(Exercise)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        InterviewQuestions/Utilities/List.cpp
        InterviewQuestions/3.FindInPartiallySortedMatrix/FindInPartiallySortedMatrix.cpp
        InterviewQuestions/4.ReplaceBlank/ReplaceBlank.cpp
        InterviewQuestions/5.PrintListInReversedOrder/PrintListInReversedOrder.cpp
        InterviewQuestions/Utilities/BinaryTree.cpp)
add_executable(Exercise ${SOURCE_FILES})