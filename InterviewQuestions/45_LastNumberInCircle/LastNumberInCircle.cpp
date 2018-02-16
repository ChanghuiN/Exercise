//
// Created by ChanghuiN on 2018/1/9.
//

#include <cstdio>
#include "LastNumberInCircle.h"


int LastRemaining_Solution2(unsigned int n, unsigned int m) {

    if (n < 1 || m < 1)
        return -1;

    int last = 0;
    for (int i = 2; i <= n; i++)
        last = (last + m) % i;

    return last;
}

void Test_LastNumberInCircle(char *testName, unsigned int n, unsigned int m, int expected) {

    if (testName != NULL)
        printf("%s begins: \n", testName);

    if (LastRemaining_Solution2(n, m) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n");

    printf("\n");
}

void Test1_LastNumberInCircle() {
    Test_LastNumberInCircle("Test1", 5, 3, 3);
}

void Test2_LastNumberInCircle() {
    Test_LastNumberInCircle("Test2", 5, 2, 2);
}

void Test3_LastNumberInCircle() {
    Test_LastNumberInCircle("Test3", 6, 7, 4);
}

void Test4_LastNumberInCircle() {
    Test_LastNumberInCircle("Test4", 6, 6, 3);
}

void Test5_LastNumberInCircle() {
    Test_LastNumberInCircle("Test5", 0, 0, -1);
}

void Test6_LastNumberInCircle() {
    Test_LastNumberInCircle("Test6", 4000, 997, 1027);
}

void Test_45_LastNumberInCircle() {

    Test1_LastNumberInCircle();
    Test2_LastNumberInCircle();
    Test3_LastNumberInCircle();
    Test4_LastNumberInCircle();
    Test5_LastNumberInCircle();
    Test6_LastNumberInCircle();
}