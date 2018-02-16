//
// Created by changhuin on 18-1-6.
//

#include <cstdio>
#include "UglyNumber.h"


int Min(int number1, int number2, int number3) {
    int result = number1 < number2 ? number1 : number2;
    return result < number3 ? result : number3;
}

int GetUglyNumber_Solution2(int index) {
    if (index <= 0)
        return 0;

    int *pUglyNumbers = new int[index];
    pUglyNumbers[0] = 1;
    int nextUglyIndex = 1;

    int *pMultiply2 = pUglyNumbers;
    int *pMultiply3 = pUglyNumbers;
    int *pMultiply5 = pUglyNumbers;

    while (nextUglyIndex < index) {
        int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
        pUglyNumbers[nextUglyIndex] = min;

        while (*pMultiply2 * 2 <= min)
            ++pMultiply2;
        while (*pMultiply3 * 3 <= min)
            ++pMultiply3;
        while (*pMultiply5 * 5 <= min)
            ++pMultiply5;

        ++nextUglyIndex;
    }

    int ugly = pUglyNumbers[nextUglyIndex - 1];
    delete[] pUglyNumbers;
    return ugly;
}

void Test_UglyNumber(int index, int expected) {

    if(GetUglyNumber_Solution2(index) == expected)
        printf("solution2 passed\n");
    else
        printf("solution2 failed\n");
}

void Test_34_UglyNumber() {

    Test_UglyNumber(1, 1);

    Test_UglyNumber(2, 2);
    Test_UglyNumber(3, 3);
    Test_UglyNumber(4, 4);
    Test_UglyNumber(5, 5);
    Test_UglyNumber(6, 6);
    Test_UglyNumber(7, 8);
    Test_UglyNumber(8, 9);
    Test_UglyNumber(9, 10);
    Test_UglyNumber(10, 12);
    Test_UglyNumber(11, 15);

    Test_UglyNumber(1500, 859963392);

    Test_UglyNumber(0, 0);
}