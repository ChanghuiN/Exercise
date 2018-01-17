//
// Created by changhuin on 18-1-6.
//

// 把数组排成最小的数
#ifndef EXERCISE_SORTARRAYFORMINNUMBER_H
#define EXERCISE_SORTARRAYFORMINNUMBER_H


void PrintMinNumber(int* numbers, int length);

int compare(const void* strNumber1, const void* strNumber2);

void Test_SortArrayForMinNumber(char* testName, int* numbers, int length, char* expectedResult);

void Test_33_SortArrayForMinNumber();

#endif //EXERCISE_SORTARRAYFORMINNUMBER_H
