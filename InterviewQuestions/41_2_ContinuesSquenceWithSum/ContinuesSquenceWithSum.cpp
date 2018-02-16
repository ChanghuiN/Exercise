//
// Created by ChanghuiN on 2018/1/9.
//

#include <cstdio>
#include "ContinuesSquenceWithSum.h"


void FindContinuousSequence(int sum) {
    if (sum < 3)
        return;

    int small = 1;
    int big = 2;
    int middle = (1 + sum) / 2;
    int curSum = small + big;

    while (small < middle) {
        if (curSum == sum)
            PrintContinuousSequence(small, big);
        while (curSum > sum && small < middle) {
            curSum -= small;
            small++;
            if (curSum == sum)
                PrintContinuousSequence(small, big);
        }
        big++;
        curSum += big;
    }
}

// 打印结果
void PrintContinuousSequence(int small, int big) {
    for(int i = small; i <= big; ++ i)
        printf("%d ", i);

    printf("\n");
}

void Test_ContinuesSquenceWithSum(char* testName, int sum) {

    if(testName != NULL)
        printf("%s for %d begins: \n", testName, sum);

    FindContinuousSequence(sum);
}

void Test_41_2_ContinuesSquenceWithSum() {

    Test_ContinuesSquenceWithSum("test1", 1);
    Test_ContinuesSquenceWithSum("test2", 3);
    Test_ContinuesSquenceWithSum("test3", 4);
    Test_ContinuesSquenceWithSum("test4", 9);
    Test_ContinuesSquenceWithSum("test5", 15);
    Test_ContinuesSquenceWithSum("test6", 100);
}