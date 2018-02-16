//
// Created by ChanghuiN on 2018/1/9.
//

#include <cstdio>
#include <cstring>
#include "ReverseWordsInSentence.h"
#include "../Utilities/StringUtil.h"


char *ReverseSentence(char *pData) {

    if (pData == NULL)
        return NULL;

    char *pBegin = pData;

    char *pEnd = pData;
    while (*pEnd != '\0')
        pEnd++;
    pEnd--;

    // 翻转整个句子
    Reverse(pBegin, pEnd);

    // 翻转句子中的每个单词
    pBegin = pEnd = pData;
    while (*pBegin != '\0')
        if (*pBegin == ' ') {
            pBegin++;
            pEnd++;
        } else if (*pEnd == ' ' || *pEnd == '\0') {
            Reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        } else
            pEnd++;
    return pData;
}

void Test_ReverseWordsInSentence(char *testName, char *input, char *expectedResult) {

    if (testName != NULL)
        printf("%s begins: ", testName);

    ReverseSentence(input);

    if ((input == NULL && expectedResult == NULL)
        || (input != NULL && strcmp(input, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// 功能测试，句子中有多个单词
void Test1_ReverseWordsInSentence() {
    char input[] = "I am a student.";
    char expected[] = "student. a am I";

    Test_ReverseWordsInSentence("Test1", input, expected);
}

// 功能测试，句子中只有一个单词
void Test2_ReverseWordsInSentence() {
    char input[] = "Wonderful";
    char expected[] = "Wonderful";

    Test_ReverseWordsInSentence("Test2", input, expected);
}

// 鲁棒性测试
void Test3_ReverseWordsInSentence() {
    Test_ReverseWordsInSentence("Test3", NULL, NULL);
}

// 边界值测试，测试空字符串
void Test4_ReverseWordsInSentence() {
    Test_ReverseWordsInSentence("Test4", "", "");
}

// 边界值测试，字符串中只有空格
void Test5_ReverseWordsInSentence() {
    char input[] = "   ";
    char expected[] = "   ";
    Test_ReverseWordsInSentence("Test5", input, expected);
}

void Test_42_1_ReverseWordsInSentence() {

    Test1_ReverseWordsInSentence();
    Test2_ReverseWordsInSentence();
    Test3_ReverseWordsInSentence();
    Test4_ReverseWordsInSentence();
    Test5_ReverseWordsInSentence();
}