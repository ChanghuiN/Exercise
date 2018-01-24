//
// Created by ChanghuiN on 2018/1/4.
//

#include <cstdio>
#include "NumberOf1InBinary.h"

// 与 <<1 与
int NumberOf1_Solution1(int n) {
    int count = 0;
    unsigned int flag = 1;
    while (flag) {
        if (n & flag)
            count++;
        flag = flag << 1;
    }
    return count;
}

// 与自身与
int NumberOf1_Solution2(int n) {
    int count = 0;
    while (n) {
        count++;
        n = n & (n - 1);
    }
    return count;
}

void Test_NumberOf1InBinary(int number, unsigned int expected) {
    int actual = NumberOf1_Solution1(number);
    printf("Solution1: Test for %p %s.\n", number, actual == expected? "passed": "failed");

    actual = NumberOf1_Solution2(number);
    printf("Solution2: Test for %p %s.\n", number, actual == expected? "passed": "failed");

    printf("\n");
}

void Tesst_10_NumberOf1InBinary() {

    // 输入0，期待的输出是0
    Test_NumberOf1InBinary(0, 0);

    // 输入1，期待的输出是1
    Test_NumberOf1InBinary(1, 1);

    // 输入10，期待的输出是2
    Test_NumberOf1InBinary(10, 2);

    // 输入0x7FFFFFFF，期待的输出是31
    Test_NumberOf1InBinary(0x7FFFFFFF, 31);

    // 输入0xFFFFFFFF（负数），期待的输出是32
    Test_NumberOf1InBinary(0xFFFFFFFF, 32);

    // 输入0x80000000（负数），期待的输出是1
    Test_NumberOf1InBinary(0x80000000, 1);
}