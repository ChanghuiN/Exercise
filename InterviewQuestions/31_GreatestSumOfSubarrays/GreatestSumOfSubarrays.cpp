//
// Created by ChanghuiN on 2018/1/5.
//

#include <cstdio>
#include "GreatestSumOfSubarrays.h"


bool g_InvalidInput_31 = false;

int FindGreatestSumOfSubArray(int *pData, int nLength) {

    if ((pData == NULL) || (nLength <= 0)) {
        g_InvalidInput_31 = true;
        return 0;
    }

    g_InvalidInput_31 = false;

    int nCurSum = 0;
    int nGreatestSum = 0x80000000;
    for (int i = 0; i < nLength; ++i) {
        if (nCurSum <= 0)
            nCurSum = pData[i];
        else
            nCurSum += pData[i];

        if (nCurSum > nGreatestSum)
            nGreatestSum = nCurSum;
    }

    return nGreatestSum;
}

// ====================测试代码====================
void Test_GreatestSumOfSubarrays(char *testName, int *pData, int nLength, int expected, bool expectedFlag) {

    if (testName != NULL)
        printf("%s begins: \n", testName);

    int result = FindGreatestSumOfSubArray(pData, nLength);
    if (result == expected && expectedFlag == g_InvalidInput_31)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1_GreatestSumOfSubarrays() {
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    Test_GreatestSumOfSubarrays("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test2_GreatestSumOfSubarrays() {
    int data[] = {-2, -8, -1, -5, -9};
    Test_GreatestSumOfSubarrays("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test3_GreatestSumOfSubarrays() {
    int data[] = {2, 8, 1, 5, 9};
    Test_GreatestSumOfSubarrays("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// 无效输入
void Test4_GreatestSumOfSubarrays() {
    Test_GreatestSumOfSubarrays("Test4", NULL, 0, 0, true);
}

void Test_31_GreatestSumOfSubarrays() {

    Test1_GreatestSumOfSubarrays();
    Test2_GreatestSumOfSubarrays();
    Test3_GreatestSumOfSubarrays();
    Test4_GreatestSumOfSubarrays();
}