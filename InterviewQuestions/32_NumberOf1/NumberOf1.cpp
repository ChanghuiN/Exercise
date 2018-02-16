//
// Created by changhuin on 18-1-6.
//

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "NumberOf1.h"


int NumberOf1Between1AndN_Solution2(int n) {

    if(n <= 0)
        return 0;

    char strN[50];
    sprintf(strN, "%d", n);

    return NumberOf1(strN);
}

int NumberOf1(const char* strN) {

    if(!strN || *strN < '0' || *strN > '9' || *strN == '\0')
        return 0;

    int first = *strN - '0';
    unsigned int length = strlen(strN);

    if (length == 1 && first == 0)
        return 0;
    if (length == 1 && first > 0)
        return 1;

    // 假设strN是"21345"
    // numFirstDigit是数字10000-19999的第一个位中1的数目
    int numFirstDigit = 0;
    if(first > 1)
        numFirstDigit = PowerBase10(length - 1);
    else if(first == 1)
        numFirstDigit = atoi(strN + 1) + 1;

    // numOtherDigits是01346-21345除了第一位之外的数位中1的数目
    int numOtherDigits = first * (length - 1) * PowerBase10(length - 2);
    // numRecursive是1-1345中1的数目
    int numRecursive = NumberOf1(strN + 1);

    return numFirstDigit + numOtherDigits + numRecursive;

}

int PowerBase10(unsigned int n) {
    int result = 1;
    for (unsigned int i = 0; i < n; ++i) {
        result *= 10;
    }
    return result;
}

void Test_NumberOf1(char* testName, int n, int expected) {

    if(testName != NULL)
        printf("%s begins: \n", testName);

    int result = NumberOf1Between1AndN_Solution2(n);
    printf("result: %d \n", result);
    if(result == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n");

    printf("\n");
}

void Test_32_NumberOf1() {

    Test_NumberOf1("Test1", 1, 1);
    Test_NumberOf1("Test2", 5, 1);
    Test_NumberOf1("Test3", 10, 2);
    Test_NumberOf1("Test4", 55, 16);
    Test_NumberOf1("Test5", 99, 20);
    Test_NumberOf1("Test6", 10000, 4001);
    Test_NumberOf1("Test7", 21345, 18821);
    Test_NumberOf1("Test8", 0, 0);
}