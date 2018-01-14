//
// Created by ChanghuiN on 2018/1/4.
//

// 调整数组顺序使奇数位于偶数前面
#ifndef EXERCISE_REORDERARRAY_H
#define EXERCISE_REORDERARRAY_H


void ReorderOddEven_1(int *pData, unsigned int length);

// 增加函数应用
void ReorderOddEven_2(int *pData, unsigned int length);

void Reorder(int *pData, unsigned int length, bool (*func)(int));

void Test_ReorderArray(char* testName, int numbers[], int length);

void Test_14_ReorderArray();


#endif //EXERCISE_REORDERARRAY_H
