//
// Created by changhuin on 18-1-6.
//

#include <cstdio>
#include "NumberOfK.h"


int GetFirstK(int *data, int length, int k, int start, int end) {

    if (start > end)
        return -1;

    int middleIndex = (start + end) / 2;
    int middleData = data[middleIndex];

    if (middleData == k) {
        if ((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0)
            return middleIndex;
        else
            end = middleIndex - 1;
    } else if (middleData > k)
        end = middleIndex - 1;
    else
        start = middleIndex + 1;

    return GetFirstK(data, length, k, start, end);
}

int GetLastK(int *data, int length, int k, int start, int end) {

    if (start > end)
        return -1;

    int middleIndex = (start + end) / 2;
    int middleData = data[middleIndex];

    if (middleData == k) {
        if ((middleIndex < length - 1 && data[middleIndex + 1] != k) || middleIndex == length - 1)
            return middleIndex;
        else
            start = middleIndex + 1;
    } else if (middleData < k)
        start = middleIndex + 1;
    else
        end = middleIndex - 1;

    return GetLastK(data, length, k, start, end);
}

int GetNumberOfK(int *data, int length, int k) {

    int number = 0;

    if (data != NULL && length > 0) {
        int first = GetFirstK(data, length, k, 0, length - 1);
        int last = GetLastK(data, length, k, 0, length - 1);

        if (first > -1 && last > -1)
            number = last - first + 1;
    }

    return number;
}

void Test_NumberOfK(char *testName, int data[], int length, int k, int expected) {

    if (testName != NULL)
        printf("%s begins: ", testName);

    int result = GetNumberOfK(data, length, k);
    if (result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 查找的数字出现在数组的中间
void Test1_NumberOfK() {
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    Test_NumberOfK("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的开头
void Test2_NumberOfK() {
    int data[] = {3, 3, 3, 3, 4, 5};
    Test_NumberOfK("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的结尾
void Test3_NumberOfK() {
    int data[] = {1, 2, 3, 3, 3, 3};
    Test_NumberOfK("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数字不存在
void Test4_NumberOfK() {
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test_NumberOfK("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// 查找的数字比第一个数字还小，不存在
void Test5_NumberOfK() {
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test_NumberOfK("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// 查找的数字比最后一个数字还大，不存在
void Test6_NumberOfK() {
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test_NumberOfK("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// 数组中的数字从头到尾都是查找的数字
void Test7_NumberOfK() {
    int data[] = {3, 3, 3, 3};
    Test_NumberOfK("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
void Test8_NumberOfK() {
    int data[] = {3, 3, 3, 3};
    Test_NumberOfK("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// 数组中只有一个数字，是查找的数字
void Test9_NumberOfK() {
    int data[] = {3};
    Test_NumberOfK("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// 数组中只有一个数字，不是查找的数字
void Test10_NumberOfK() {
    int data[] = {3};
    Test_NumberOfK("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// 鲁棒性测试，数组空指针
void Test11_NumberOfK() {
    Test_NumberOfK("Test11", NULL, 0, 0, 0);
}

void Test_38_NumberOfK() {

    Test1_NumberOfK();
    Test2_NumberOfK();
    Test3_NumberOfK();
    Test4_NumberOfK();
    Test5_NumberOfK();
    Test6_NumberOfK();
    Test7_NumberOfK();
    Test8_NumberOfK();
    Test9_NumberOfK();
    Test10_NumberOfK();
    Test11_NumberOfK();
}