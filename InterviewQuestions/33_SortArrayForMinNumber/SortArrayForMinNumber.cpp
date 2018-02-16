//
// Created by changhuin on 18-1-6.
//

#include <cstdio>
#include <algorithm>
#include "SortArrayForMinNumber.h"


// int型整数用十进制表示最多只有10位
const int g_MaxNumberLength = 10;

char *g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
char *g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

void PrintMinNumber(int *numbers, int length) {
    if (numbers == NULL || length <= 0)
        return;

    char **strNumbers = (char **) (new int[length]);
    for (int i = 0; i < length; ++i) {
        strNumbers[i] = new char[g_MaxNumberLength + 1];
        sprintf(strNumbers[i], "%d", numbers[i]);
    }

    qsort(strNumbers, length, sizeof(char *), compare_SortArrayForMinNumber);

    for (int i = 0; i < length; ++i)
        printf("%s", strNumbers[i]);
    printf("\n");

    for (int i = 0; i < length; ++i)
        delete[] strNumbers[i];
    delete[] strNumbers;
}

// 如果[strNumber1][strNumber2] > [strNumber2][strNumber1], 返回值大于0
// 如果[strNumber1][strNumber2] = [strNumber2][strNumber1], 返回值等于0
// 如果[strNumber1][strNumber2] < [strNumber2][strNumber1], 返回值小于0
int compare_SortArrayForMinNumber(const void *strNumber1, const void *strNumber2) {

    // [strNumber1][strNumber2]
    strcpy(g_StrCombine1, *(const char **) (strNumber1));
    strcat(g_StrCombine1, *(const char **) (strNumber2));

    // [strNumber2][strNumber1]
    strcpy(g_StrCombine2, *(const char **) (strNumber2));
    strcat(g_StrCombine2, *(const char **) (strNumber1));

    return strcmp(g_StrCombine1, g_StrCombine2);

}

void Test_SortArrayForMinNumber(char *testName, int *numbers, int length, char *expectedResult) {

    if (testName != NULL)
        printf("%s begins:\n", testName);

    if (expectedResult != NULL)
        printf("Expected result is: \t%s\n", expectedResult);

    printf("Actual result is: \t");
    PrintMinNumber(numbers, length);

    printf("\n");
}

void Test1_SortArrayForMinNumber() {
    int numbers[] = {3, 5, 1, 4, 2};
    Test_SortArrayForMinNumber("Test1", numbers, sizeof(numbers) / sizeof(int), "12345");
}

void Test2_SortArrayForMinNumber() {
    int numbers[] = {3, 32, 321};
    Test_SortArrayForMinNumber("Test2", numbers, sizeof(numbers) / sizeof(int), "321323");
}

void Test3_SortArrayForMinNumber() {
    int numbers[] = {3, 323, 32123};
    Test_SortArrayForMinNumber("Test3", numbers, sizeof(numbers) / sizeof(int), "321233233");
}

void Test4_SortArrayForMinNumber() {
    int numbers[] = {1, 11, 111};
    Test_SortArrayForMinNumber("Test4", numbers, sizeof(numbers) / sizeof(int), "111111");
}

// 数组中只有一个数字
void Test5_SortArrayForMinNumber() {
    int numbers[] = {321};
    Test_SortArrayForMinNumber("Test5", numbers, sizeof(numbers) / sizeof(int), "321");
}

void Test6_SortArrayForMinNumber() {
    Test_SortArrayForMinNumber("Test6", NULL, 0, "Don't print anything.");
}


void Test_33_SortArrayForMinNumber() {

    Test1_SortArrayForMinNumber();
    Test2_SortArrayForMinNumber();
    Test3_SortArrayForMinNumber();
    Test4_SortArrayForMinNumber();
    Test5_SortArrayForMinNumber();
    Test6_SortArrayForMinNumber();
}