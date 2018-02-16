//
// Created by ChanghuiN on 2018/1/9.
//

#include <cstdio>
#include "AddTwoNumbers.h"


int Add(int num1, int num2) {
    int sum, carry;
    do {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;

        num1 = sum;
        num2 = carry;
    } while (num2 != 0);
    return num1;
}

void Test_AddTwoNumbers(int num1, int num2, int expected) {

    int result = Add(num1, num2);
    if(result == expected)
        printf("%d + %d is %d. Passed\n", num1, num2, result);
    else
        printf("%d + %d is %d. Failed\n", num1, num2, result);
}

void Test_47_AddTwoNumbers() {

    Test_AddTwoNumbers(1, 2, 3);
    Test_AddTwoNumbers(111, 899, 1010);

    Test_AddTwoNumbers(-1, 2, 1);
    Test_AddTwoNumbers(1, -2, -1);

    Test_AddTwoNumbers(3, 0, 3);
    Test_AddTwoNumbers(0, -4, -4);

    Test_AddTwoNumbers(-2, -8, -10);
}