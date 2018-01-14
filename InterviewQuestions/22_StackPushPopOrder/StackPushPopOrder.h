//
// Created by ChanghuiN on 2018/1/4.
//

// 栈的压入、弹出序列
#ifndef EXERCISE_STACKPUSHPOPORDER_H
#define EXERCISE_STACKPUSHPOPORDER_H


bool IsPopOrder(const int* pPush, const int* pPop, int nLength);

void Test_StackPushPopOrder(char* testName, const int* pPush, const int* pPop, int nLength, bool expected);

void Test_22_StackPushPopOrder();

#endif //EXERCISE_STACKPUSHPOPORDER_H
