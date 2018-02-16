//
// Created by ChanghuiN on 2018/1/9.
//

#include <cstdio>
#include <cstring>
#include "LeftRotateString.h"
#include "../Utilities/StringUtil.h"


char *LeftRotateString(char *pStr, int n) {
    if (pStr == NULL)
        return NULL;

    int nLength = strlen(pStr);
    if (nLength > 0 && n > 0 && nLength > n) {
        char *pFirstStart = pStr;
        char *pFirstEnd = pStr + n - 1;
        char *pSecondStart = pStr + n;
        char *pSecondEnd = pStr + nLength - 1;

        // 翻转字符串的前面n个字符
        Reverse(pFirstStart, pFirstEnd);
        // 翻转字符串的后面部分
        Reverse(pSecondStart, pSecondEnd);
        // 翻转整个字符串
        Reverse(pFirstStart, pSecondEnd);
    }
    return pStr;
}

void Test_LeftRotateString(char *testName, char *input, int num, char *expectedResult) {

    if (testName != NULL)
        printf("%s begins: ", testName);

    char *result = LeftRotateString(input, num);

    if ((input == NULL && expectedResult == NULL)
        || (input != NULL && strcmp(result, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// 功能测试
void Test1_LeftRotateString() {
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    Test_LeftRotateString("Test1", input, 2, expected);
}

// 边界值测试
void Test2_LeftRotateString() {
    char input[] = "abcdefg";
    char expected[] = "bcdefga";

    Test_LeftRotateString("Test2", input, 1, expected);
}

// 边界值测试
void Test3_LeftRotateString() {
    char input[] = "abcdefg";
    char expected[] = "gabcdef";

    Test_LeftRotateString("Test3", input, 6, expected);
}

// 鲁棒性测试
void Test4_LeftRotateString() {
    Test_LeftRotateString("Test4", NULL, 6, NULL);
}

// 鲁棒性测试
void Test5_LeftRotateString() {
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test_LeftRotateString("Test5", input, 0, expected);
}

// 鲁棒性测试
void Test6_LeftRotateString() {
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test_LeftRotateString("Test6", input, 7, expected);
}

void Test_42_2_LeftRotateString() {

    Test1_LeftRotateString();
    Test2_LeftRotateString();
    Test3_LeftRotateString();
    Test4_LeftRotateString();
    Test5_LeftRotateString();
    Test6_LeftRotateString();
}