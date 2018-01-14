//
// Created by ChanghuiN on 2018/1/4.
//

// 打印从1到最大的n位数
#ifndef EXERCISE_PRINT1TOMAXOFNDIGITS_H
#define EXERCISE_PRINT1TOMAXOFNDIGITS_H


void Print1ToMaxOfNDigits_1(int n);

// 字符串number表示一个数字，在 number上增加1
// 如果做加法溢出，则返回true；否则为false
bool Increment(char* number);

void Print1ToMaxOfNDigits_2(int n);

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

// ====================公共函数====================
// 字符串number表示一个数字，数字有若干个0开头
// 打印出这个数字，并忽略开头的0
void PrintNumber(char* number)

void Test_Print1ToMaxOfNDigits();

void Test_12_Print1ToMaxOfNDigits();


#endif //EXERCISE_PRINT1TOMAXOFNDIGITS_H
