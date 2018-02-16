//
// Created by ChanghuiN on 2018/1/5.
//

#include <cstdio>
#include "MoreThanHalfNumber.h"
#include "../Utilities/Array.h"

bool g_bInputInvalid = false;

// 检查无效的数组
bool CheckInvalidArray(int *numbers, int length) {

    g_bInputInvalid = false;
    if (numbers == NULL && length <= 0)
        g_bInputInvalid = true;

    return g_bInputInvalid;
}

// 检查数字是否为超出一半
bool CheckMoreThanHalf(int *numbers, int length, int number) {

    int times = 0;
    for (int i = 0; i < length; ++i) {
        if (numbers[i] == number)
            times++;
    }

    bool isMoreThanHalf = true;
    if (times * 2 <= length) {
        g_bInputInvalid = true;
        isMoreThanHalf = false;
    }
    return isMoreThanHalf;
}

// 基于Partition函数的算法
int MoreThanHalfNum_Solution1(int *numbers, int length) {

    if (CheckInvalidArray(numbers, length))
        return 0;

    int middle = length >> 1;
    int start = 0;
    int end = length - 1;
    int index = Partition(numbers, length, start, end);
    while (index != middle) {
        if (index > middle) {
            end = index - 1;
            index = Partition(numbers, length, start, end);
        } else {
            start = index + 1;
            index = Partition(numbers, length, start, end);
        }
    }

    int result = numbers[middle];
    if (!CheckMoreThanHalf(numbers, length, result))
        result = 0;

    return result;
}

// 基于数组特点
int MoreThanHalfNum_Solution2(int *numbers, int length) {
    if (CheckInvalidArray(numbers, length))
        return 0;

    int result = numbers[0];
    int times = 1;
    for (int i = 0; i < length; ++i) {
        if (times == 0) {
            result = numbers[i];
            times = 1;
        } else if (numbers[i] == result)
            times++;
        else
            times--;
    }

    if (!CheckMoreThanHalf(numbers, length, result))
        result = 0;

    return result;
}

void Test_MoreThanHalfNumber(char *testName, int *numbers, int length, int expectedValue, bool expectedFlag) {

    if (testName != NULL)
        printf("%s begins: \n", testName);

    int *copy = new int[length];
    for (int i = 0; i < length; ++i)
        copy[i] = numbers[i];

    printf("Test for solution1: ");
    int result = MoreThanHalfNum_Solution1(numbers, length);
    if (result == expectedValue && g_bInputInvalid == expectedFlag)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Test for solution2: ");
    result = MoreThanHalfNum_Solution2(copy, length);
    if (result == expectedValue && g_bInputInvalid == expectedFlag)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    delete[] copy;
}

// 存在出现次数超过数组长度一半的数字
void Test1_MoreThanHalfNumber() {
    int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Test_MoreThanHalfNumber("Test1", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 不存在出现次数超过数组长度一半的数字
void Test2_MoreThanHalfNumber() {
    int numbers[] = {1, 2, 3, 2, 4, 2, 5, 2, 3};
    Test_MoreThanHalfNumber("Test2", numbers, sizeof(numbers) / sizeof(int), 0, true);
}

// 出现次数超过数组长度一半的数字都出现在数组的前半部分
void Test3_MoreThanHalfNumber() {
    int numbers[] = {2, 2, 2, 2, 2, 1, 3, 4, 5};
    Test_MoreThanHalfNumber("Test3", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 出现次数超过数组长度一半的数字都出现在数组的后半部分
void Test4_MoreThanHalfNumber() {
    int numbers[] = {1, 3, 4, 5, 2, 2, 2, 2, 2};
    Test_MoreThanHalfNumber("Test4", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 输入空指针
void Test5_MoreThanHalfNumber() {
    int numbers[] = {1};
    Test_MoreThanHalfNumber("Test5", numbers, 1, 1, false);
}

// 输入空指针
void Test6_MoreThanHalfNumber() {
    Test_MoreThanHalfNumber("Test6", NULL, 0, 0, true);
}


void Test_29_MoreThanHalfNumber() {

    Test1_MoreThanHalfNumber();
    Test2_MoreThanHalfNumber();
    Test3_MoreThanHalfNumber();
    Test4_MoreThanHalfNumber();
    Test5_MoreThanHalfNumber();
    Test6_MoreThanHalfNumber();
}