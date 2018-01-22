//
// Created by ChanghuiN on 2018/1/9.
//

// 递增数列中找出和为s的两个数
#ifndef EXERCISE_TWONUMBERSWITHSUM_H
#define EXERCISE_TWONUMBERSWITHSUM_H



bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int* num2);

void Test_TwoNumbersWithSum(char* testName, int data[], int length, int sum, bool expectedReturn);

void Test_41_1_TwoNumbersWithSum();

#endif //EXERCISE_TWONUMBERSWITHSUM_H
