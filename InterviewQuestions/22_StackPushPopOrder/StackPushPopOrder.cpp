//
// Created by ChanghuiN on 2018/1/4.
//

#include <cstdlib>
#include <cstdio>
#include <stack>
#include "StackPushPopOrder.h"


bool IsPopOrder(const int *pPush, const int *pPop, int nLength) {

    bool bPossible = false;

    if (pPush != NULL && pPop != NULL && nLength > 0) {
        const int *pNextPush = pPush;
        const int *pNextPop = pPop;

        std::stack<int> stackData;

        while (pNextPop - pPop < nLength) {
            // 当辅助栈的栈顶元素不是要弹出的元素
            // 先压入一些数字入栈
            while (stackData.empty() || stackData.top() != *pNextPop) {
                // 如果所有数字都压入辅助栈了，退出循环
                if (pNextPush - pPush == nLength)
                    break;

                stackData.push(*pNextPush);

                pNextPush++;
            }

            if (stackData.top() != *pNextPop)
                break;

            stackData.pop();
            pNextPop++;
        }

        if (stackData.empty() && pNextPop - pPop == nLength)
            bPossible = true;
    }

    return bPossible;
}

void Test_StackPushPopOrder(char *testName, const int *pPush, const int *pPop, int nLength, bool expected) {

    if (testName != NULL)
        printf("%s begins: ", testName);

    if (IsPopOrder(pPush, pPop, nLength) == expected)
        printf("Passed.\n");
    else
        printf("failed.\n");
}

void Test1_StackPushPopOrder() {
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 5, 3, 2, 1};

    Test_StackPushPopOrder("Test1", push, pop, nLength, true);
}

void Test2_StackPushPopOrder() {
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 2, 1};

    Test_StackPushPopOrder("Test2", push, pop, nLength, true);
}

void Test3_StackPushPopOrder() {
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 3, 5, 1, 2};

    Test_StackPushPopOrder("Test3", push, pop, nLength, false);
}

void Test4_StackPushPopOrder() {
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 1, 2};

    Test_StackPushPopOrder("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5_StackPushPopOrder() {
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {2};

    Test_StackPushPopOrder("Test5", push, pop, nLength, false);
}

void Test6_StackPushPopOrder() {
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {1};

    Test_StackPushPopOrder("Test6", push, pop, nLength, true);
}

void Test7_StackPushPopOrder() {
    Test_StackPushPopOrder("Test7", NULL, NULL, 0, false);
}


void Test_22_StackPushPopOrder() {

    Test1_StackPushPopOrder();
    Test2_StackPushPopOrder();
    Test3_StackPushPopOrder();
    Test4_StackPushPopOrder();
    Test5_StackPushPopOrder();
    Test6_StackPushPopOrder();
    Test7_StackPushPopOrder();

}