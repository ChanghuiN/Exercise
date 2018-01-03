cmake_minimum_required(VERSION 3.8)
project(Exercise)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        InterviewQuestions/Utilities/List.cpp
        InterviewQuestions/Utilities/Tree.cpp
        InterviewQuestions/Utilities/BinaryTree.cpp
        InterviewQuestions/03_FindInPartiallySortedMatrix/FindInPartiallySortedMatrix.cpp
        InterviewQuestions/04_ReplaceBlank/ReplaceBlank.cpp
        InterviewQuestions/05_PrintListInReversedOrder/PrintListInReversedOrder.cpp
        InterviewQuestions/06_ConstructBinaryTree/ConstructBinaryTree.cpp
        InterviewQuestions/07_QueueWithTwoStacks/QueueWithTwoStacks.cpp
        InterviewQuestions/07_QueueWithTwoStacks/QueueWithTwoStacks.h
        InterviewQuestions/08_MinNumberInRotatedArray/MinNumberInRotatedArray.cpp
        InterviewQuestions/08_MinNumberInRotatedArray/MinNumberInRotatedArray.h
        InterviewQuestions/09_Fibonacci/Fibonacci.cpp
        InterviewQuestions/09_Fibonacci/Fibonacci.h
        InterviewQuestions/10_NumberOf1InBinary/NumberOf1InBinary.cpp
        InterviewQuestions/10_NumberOf1InBinary/NumberOf1InBinary.h
        InterviewQuestions/11_Power/Power.cpp
        InterviewQuestions/11_Power/Power.h
        InterviewQuestions/12_Print1ToMaxOfNDigits/Print1ToMaxOfNDigits.cpp
        InterviewQuestions/12_Print1ToMaxOfNDigits/Print1ToMaxOfNDigits.h
        InterviewQuestions/13_DeleteNodeInList/DeleteNodeInList.cpp
        InterviewQuestions/13_DeleteNodeInList/DeleteNodeInList.h
        InterviewQuestions/14_ReorderArray/ReorderArray.cpp
        InterviewQuestions/14_ReorderArray/ReorderArray.h
        InterviewQuestions/15_KthNodeFromEnd/KthNodeFromEnd.cpp
        InterviewQuestions/15_KthNodeFromEnd/KthNodeFromEnd.h
        InterviewQuestions/16_ReverseList/ReverseList.cpp
        InterviewQuestions/16_ReverseList/ReverseList.h
        InterviewQuestions/17_MergeSortedLists/MergeSortedLists.cpp
        InterviewQuestions/17_MergeSortedLists/MergeSortedLists.h
        InterviewQuestions/18_SubstructureInTree/SubstructureInTree.cpp
        InterviewQuestions/18_SubstructureInTree/SubstructureInTree.h
        InterviewQuestions/19_MirrorOfBinaryTree/MirrorOfBinaryTree.cpp
        InterviewQuestions/19_MirrorOfBinaryTree/MirrorOfBinaryTree.h
        InterviewQuestions/20_PrintMatrix/PrintMatrix.cpp
        InterviewQuestions/20_PrintMatrix/PrintMatrix.h)
add_executable(Exercise ${SOURCE_FILES})