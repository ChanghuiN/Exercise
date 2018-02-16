//
// Created by ChanghuiN on 2018/1/9.
//

#include <cstdio>
#include <cstdlib>
#include "ContinousCards.h"


int compare_ContinousCards(const void *arg1, const void *arg2) {
    return *(int *) arg1 - *(int *) arg2;
}

bool IsContinuous(int *numbers, int length) {
    if (numbers == NULL || length < 3)
        return false;

    qsort(numbers, length, sizeof(int), compare_ContinousCards);

    int numberOfZero = 0;
    int numberOfGap = 0;

    // 统计数组中0的个数
    for (int i = 0; i < length && numbers[i] == 0; ++i)
        ++numberOfZero;

    // 统计数组中的间隔数目
    int small = numberOfZero;
    int big = small + 1;
    while (big < length) {

        // 两个数相等，有对子，不可能是顺子
        if (numbers[small] == numbers[big])
            return false;

        numberOfGap += numbers[big] - numbers[small] - 1;
        small = big;
        ++big;
    }
    return (numberOfGap > numberOfZero) ? false : true;

}

void Test_ContinousCards(char *testName, int *numbers, int length, bool expected) {

    if (testName != NULL)
        printf("%s begins: ", testName);

    if (IsContinuous(numbers, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1_ContinousCards() {
    int numbers[] = {1, 3, 2, 5, 4};
    Test_ContinousCards("Test1", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test2_ContinousCards() {
    int numbers[] = {1, 3, 2, 6, 4};
    Test_ContinousCards("Test2", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test3_ContinousCards() {
    int numbers[] = {0, 3, 2, 6, 4};
    Test_ContinousCards("Test3", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test4_ContinousCards() {
    int numbers[] = {0, 3, 1, 6, 4};
    Test_ContinousCards("Test4", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test5_ContinousCards() {
    int numbers[] = {1, 3, 0, 5, 0};
    Test_ContinousCards("Test5", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test6_ContinousCards() {
    int numbers[] = {1, 3, 0, 7, 0};
    Test_ContinousCards("Test6", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test7_ContinousCards() {
    int numbers[] = {1, 0, 0, 5, 0};
    Test_ContinousCards("Test7", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test8_ContinousCards() {
    int numbers[] = {1, 0, 0, 7, 0};
    Test_ContinousCards("Test8", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test9_ContinousCards() {
    int numbers[] = {3, 0, 0, 0, 0};
    Test_ContinousCards("Test9", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test10_ContinousCards() {
    int numbers[] = {0, 0, 0, 0, 0};
    Test_ContinousCards("Test10", numbers, sizeof(numbers) / sizeof(int), true);
}

// 有对子
void Test11_ContinousCards() {
    int numbers[] = {1, 0, 0, 1, 0};
    Test_ContinousCards("Test11", numbers, sizeof(numbers) / sizeof(int), false);
}

// 鲁棒性测试
void Test12_ContinousCards() {
    Test_ContinousCards("Test12", NULL, 0, false);
}

void Test_44_ContinousCards() {

    Test1_ContinousCards();
    Test2_ContinousCards();
    Test3_ContinousCards();
    Test4_ContinousCards();
    Test5_ContinousCards();
    Test6_ContinousCards();
    Test7_ContinousCards();
    Test8_ContinousCards();
    Test9_ContinousCards();
    Test10_ContinousCards();
    Test11_ContinousCards();
    Test12_ContinousCards();
}