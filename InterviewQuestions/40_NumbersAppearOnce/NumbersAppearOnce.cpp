//
// Created by changhuin on 18-1-6.
//

#include <cstdio>
#include "NumbersAppearOnce.h"


void FindNumsAppearOnce(int data[], int length, int* num1, int* num2) {
    if (data == NULL || length < 2)
        return;

    int resultExclusiveOR = 0;
    for (int i = 0; i < length; ++i)
        resultExclusiveOR ^= data[i];

    unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

    *num1 = *num2 = 0;
    for (int j = 0; j < length; ++j) {
        if (IsBit1(data[j], indexOf1))
            *num1 ^= data[j];
        else
            *num2 ^= data[j];
    }

}

// 寻找第一位bit为1的位数n
unsigned int FindFirstBitIs1(int num) {
    int indexBit = 0;
    while ((num & 1) == 0 && (indexBit < 6 * sizeof(int))) {
        num = num >> 1;
        indexBit++;
    }
    return indexBit;
}

// 第n位是否为1
bool IsBit1(int num, unsigned int indexBit) {
    num = num >> indexBit;
    return (num & 1);
}

void Test_NumbersAppearOnce(char* testName, int data[], int length, int expected1, int expected2) {

    if(testName != NULL)
        printf("%s begins: ", testName);

    int result1, result2;
    FindNumsAppearOnce(data, length, &result1, &result2);

    if((expected1 == result1 && expected2 == result2) ||
       (expected2 == result1 && expected1 == result2))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

void Test1_NumbersAppearOnce()
{
    int data[] = {2, 4, 3, 6, 3, 2, 5, 5};
    Test_NumbersAppearOnce("Test1", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test2_NumbersAppearOnce()
{
    int data[] = {4, 6};
    Test_NumbersAppearOnce("Test2", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test3_NumbersAppearOnce()
{
    int data[] = {4, 6, 1, 1, 1, 1};
    Test_NumbersAppearOnce("Test3", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test_40_NumbersAppearOnce() {

    Test1_NumbersAppearOnce();
    Test2_NumbersAppearOnce();
    Test3_NumbersAppearOnce();
}