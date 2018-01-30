//
// Created by ChanghuiN on 2018/1/4.
//

#include <cstdio>
#include <cstring>
#include "Print1ToMaxOfNDigits.h"

void Print1ToMaxOfNDigits_1(int n) {
    if (n <=0 )
        return;

    char* number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    while (!Increment(number))
        PrintNumber(number);

    delete []number;
}

// 字符串number表示一个数字，在 number上增加1
// 如果做加法溢出，则返回true；否则为false
bool Increment(char *number) {

    bool isOverflow = false;
    int nTakeOver = 0;
    int length = strlen(number);

    for (int i = length - 1; i >= 0; i--) {
        int num = number[i] - '0' + nTakeOver;
        if (i == length - 1)
            num++;

        if (num >= 10) {
            if (i == 0)
                isOverflow = true;
            else {
                num -= 10;
                nTakeOver = 1;
                number[i] = '0' + num;
            }
        } else {
            number[i] = '0' + num;
            break;
        }
    }

    return isOverflow;
}

void Print1ToMaxOfNDigits_2(int n) {
    if (n <= 0)
        return;

    char* number = new char[n + 1];
    number[n] = '\0';

    for (int i = 0; i < 10; ++i) {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }

    delete []number;
}

void Print1ToMaxOfNDigitsRecursively(char *number, int length, int index) {
    if (index == length - 1) {
        PrintNumber(number);
        return;
    }

    for (int i = 0; i < 10; ++i) {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, length, index ++);
    }
}

// ====================公共函数====================
// 字符串number表示一个数字，数字有若干个0开头
// 打印出这个数字，并忽略开头的0
void PrintNumber(char *number) {

    bool isBenginning = true;
    int length = strlen(number);

    for (int i = 0; i < length; i++) {
        if (isBenginning && number[i] != '0')
            isBenginning = false;
        if (!isBenginning)
            printf("%c", number[i]);
    }

    printf("\t");
}

size_t strlen() {
    return 0;
}

void Test_Print1ToMaxOfNDigits(int n) {
    printf("Test for %d begins:\n", n);

    Print1ToMaxOfNDigits_1(n);
    printf("\n");
    Print1ToMaxOfNDigits_2(n);
    printf("\n");

    printf("Test for %d ends.\n", n);
}

void Test_12_Print1ToMaxOfNDigits() {

    Test_Print1ToMaxOfNDigits(1);
    Test_Print1ToMaxOfNDigits(2);
    Test_Print1ToMaxOfNDigits(3);
    Test_Print1ToMaxOfNDigits(0);
    Test_Print1ToMaxOfNDigits(-1);
}