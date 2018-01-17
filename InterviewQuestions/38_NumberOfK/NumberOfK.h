//
// Created by changhuin on 18-1-6.
//

// 数字在排序数组中出现的次数
#ifndef EXERCISE_NUMBEROFK_H
#define EXERCISE_NUMBEROFK_H


int GetFirstK(int* data, int length, int k, int start, int end);
int GetLastK(int* data, int length, int k, int start, int end);

int GetNumberOfK(int* data, int length, int k);

void Test_NumberOfK(char* testName, int data[], int length, int k, int expected);

void Test_38_NumberOfK();

#endif //EXERCISE_NUMBEROFK_H
