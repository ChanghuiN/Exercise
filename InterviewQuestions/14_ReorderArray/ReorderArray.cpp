//
// Created by ChanghuiN on 2018/1/4.
//

#include <cstdio>
#include "ReorderArray.h"

void PrintArray(int numbers[], int length);

void ReorderOddEven_1(int *pData, unsigned int length) {
    if (length <= 0)
        return;

    int *pBegin = pData;
    int *pEnd = pData + length - 1;
    while (pBegin < pEnd) {
        // 向后移动pBegin，直到它指向偶数
        while (pBegin < pEnd && (*pBegin & 0x1) != 0)
            pBegin++;

        // 向前移动pEnd，直到它指向奇数
        while (pBegin < pEnd && (*pEnd & 0x1) == 0)
            pEnd--;

        if (pBegin < pEnd) {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

bool isEven(int n) {
    return (n & 1) == 0;
}

// 增加函数应用，考虑拓展性
void ReorderOddEven_2(int *pData, unsigned int length) {

    Reorder(pData, length, isEven);
}

void Reorder(int *pData, unsigned int length, bool (*func)(int)) {
    if (length <= 0)
        return;

    int *pBegin = pData;
    int *pEnd = pData + length - 1;
    while (pBegin < pEnd) {
        // 向后移动pBegin，直到它指向偶数
        while (pBegin < pEnd && !func(*pBegin))
            pBegin++;

        // 向前移动pEnd，直到它指向奇数
        while (pBegin < pEnd && func(*pEnd))
            pEnd--;

        if (pBegin < pEnd) {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

void Test_ReorderArray(char *testName, int numbers[], int length) {
    if (testName != NULL)
        printf("%s begins:\n", testName);

    int *copy = new int[length];
    for (int i = 0; i < length; ++i) {
        copy[i] = numbers[i];
    }

    printf("Test for solution 1:\n");
    PrintArray(numbers, length);
    ReorderOddEven_1(numbers, length);
    PrintArray(numbers, length);

    printf("Test for solution 2:\n");
    PrintArray(copy, length);
    ReorderOddEven_2(copy, length);
    PrintArray(copy, length);

    delete[] copy;
}


void PrintArray(int numbers[], int length) {
    if (length < 0)
        return;

    for (int i = 0; i < length; ++i)
        printf("%d\t", numbers[i]);

    printf("\n");
}

void Test1_ReorderArray() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    Test_ReorderArray("Test1", numbers, sizeof(numbers) / sizeof(int));
}

void Test2_ReorderArray() {
    int numbers[] = {2, 4, 6, 1, 3, 5, 7};
    Test_ReorderArray("Test2", numbers, sizeof(numbers) / sizeof(int));
}

void Test3_ReorderArray() {
    int numbers[] = {1, 3, 5, 7, 2, 4, 6};
    Test_ReorderArray("Test3", numbers, sizeof(numbers) / sizeof(int));
}

void Test4_ReorderArray() {
    int numbers[] = {1};
    Test_ReorderArray("Test4", numbers, sizeof(numbers) / sizeof(int));
}

void Test5_ReorderArray() {
    int numbers[] = {2};
    Test_ReorderArray("Test5", numbers, sizeof(numbers) / sizeof(int));
}

void Test6_ReorderArray() {
    Test_ReorderArray("Test6", NULL, 0);
}

void Test_14_ReorderArray() {

    Test1_ReorderArray();
    Test2_ReorderArray();
    Test3_ReorderArray();
    Test4_ReorderArray();
    Test5_ReorderArray();
    Test6_ReorderArray();
}