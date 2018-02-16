//
// Created by changhuin on 18-1-6.
//

#include <cstdio>
#include "InversePairs.h"


int InversePairs(int *data, int length) {

    if(data == NULL || length < 0)
        return 0;

    int* copy = new int[length];
    for(int i = 0; i < length; ++ i)
        copy[i] = data[i];

    int count = InversePairsCore(data, copy, 0, length - 1);
    delete[] copy;

    return count;
}

int InversePairsCore(int *data, int *copy, int start, int end) {

    if (start == end) {
        copy[start] = data[start];
        return 0;
    }

    int length = (end - start) / 2;

    int left = InversePairsCore(copy, data, start, start + length);
    int right = InversePairsCore(copy, data, start + length + 1, end);

    // i初始化为前半段最后一个数字的下标
    int i = start + length;
    // j初始化为后半段最后一个数字的下标
    int j = end;
    int indexCopy = end;
    int count = 0;
    while (i >= start && j >= start + length + 1) {
        if (data[i] > data[j]) {
            copy[indexCopy--] = data[i--];
            count += j - start - length;
        } else {
            copy[indexCopy--] = data[j--];
        }
    }

    for (; i >= start; --i)
        copy[indexCopy--] = data[i];

    for (; j >= start + length + 1; --j)
        copy[indexCopy--] = data[j];

    return left + right + count;
}

void Test_InversePairs(char *testName, int *data, int length, int expected) {

    if (testName != NULL)
        printf("%s begins: ", testName);

    if (InversePairs(data, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1_InversePairs() {
    int data[] = {1, 2, 3, 4, 7, 6, 5};
    int expected = 3;

    Test_InversePairs("Test1", data, sizeof(data) / sizeof(int), expected);
}

// 递减排序数组
void Test2_InversePairs() {
    int data[] = {6, 5, 4, 3, 2, 1};
    int expected = 15;

    Test_InversePairs("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3_InversePairs() {
    int data[] = {1, 2, 3, 4, 5, 6};
    int expected = 0;

    Test_InversePairs("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4_InversePairs() {
    int data[] = {1};
    int expected = 0;

    Test_InversePairs("Test4", data, sizeof(data) / sizeof(int), expected);
}


// 数组中只有两个数字，递增排序
void Test5_InversePairs() {
    int data[] = {1, 2};
    int expected = 0;

    Test_InversePairs("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6_InversePairs() {
    int data[] = {2, 1};
    int expected = 1;

    Test_InversePairs("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7_InversePairs() {
    int data[] = {1, 2, 1, 2, 1};
    int expected = 3;

    Test_InversePairs("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8_InversePairs() {
    int expected = 0;

    Test_InversePairs("Test8", NULL, 0, expected);
}


void Test_36_InversePairs() {

    Test1_InversePairs();
    Test2_InversePairs();
    Test3_InversePairs();
    Test4_InversePairs();
    Test5_InversePairs();
    Test6_InversePairs();
    Test7_InversePairs();
    Test8_InversePairs();
}