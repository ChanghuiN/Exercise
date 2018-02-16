//
// Created by ChanghuiN on 2018/1/9.
//

#include <cstdio>
#include "TwoNumbersWithSum.h"


bool FindNumbersWithSum(int data[], int length, int sum, int *num1, int *num2) {
    bool found = false;
    if (length < 1 || num1 == NULL || num2 == NULL)
        return found;

    int ahead = length - 1;
    int behind = 0;

    while (ahead > behind) {
        int curSum = data[ahead] + data[behind];

        if (curSum == sum) {
            *num1 = data[behind];
            *num2 = data[ahead];
            found = true;
            break;
        } else if (curSum > sum)
            ahead--;
        else
            behind++;
    }
    return found;
}

void Test_TwoNumbersWithSum(char *testName, int data[], int length, int sum, bool expectedReturn) {

    if (testName != NULL)
        printf("%s begins: ", testName);

    int num1, num2;
    int result = FindNumbersWithSum(data, length, sum, &num1, &num2);
    if (result == expectedReturn) {
        if (result) {
            if (num1 + num2 == sum)
                printf("Passed. \n");
            else
                printf("Failed. \n");
        } else
            printf("Passed. \n");
    } else
        printf("Failed. \n");
}

// 存在和为s的两个数字，这两个数字位于数组的中间
void Test1_TwoNumbersWithSum() {
    int data[] = {1, 2, 4, 7, 11, 15};
    Test_TwoNumbersWithSum("Test1", data, sizeof(data) / sizeof(int), 15, true);
}

// 存在和为s的两个数字，这两个数字位于数组的两段
void Test2_TwoNumbersWithSum() {
    int data[] = {1, 2, 4, 7, 11, 16};
    Test_TwoNumbersWithSum("Test2", data, sizeof(data) / sizeof(int), 17, true);
}

// 不存在和为s的两个数字
void Test3_TwoNumbersWithSum() {
    int data[] = {1, 2, 4, 7, 11, 16};
    Test_TwoNumbersWithSum("Test3", data, sizeof(data) / sizeof(int), 10, false);
}

// 鲁棒性测试
void Test4_TwoNumbersWithSum() {
    Test_TwoNumbersWithSum("Test4", NULL, 0, 0, false);
}

void Test_41_1_TwoNumbersWithSum() {

    Test1_TwoNumbersWithSum();
    Test2_TwoNumbersWithSum();
    Test3_TwoNumbersWithSum();
    Test4_TwoNumbersWithSum();
}