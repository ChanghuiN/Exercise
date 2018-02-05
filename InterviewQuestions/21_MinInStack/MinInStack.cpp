//
// Created by ChanghuiN on 2018/1/4.
//

#include <cstdio>
#include "MinInStack.h"


void Test_MinInStack(char* testName, const StackWithMin<int>& stack, int expected) {
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(stack.min() == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test_21_MinInStack() {

    StackWithMin<int> stack;

    stack.push(3);
    Test_MinInStack("Test1", stack, 3);

    stack.push(4);
    Test_MinInStack("Test2", stack, 3);

    stack.push(2);
    Test_MinInStack("Test3", stack, 2);

    stack.push(3);
    Test_MinInStack("Test4", stack, 2);

    stack.pop();
    Test_MinInStack("Test5", stack, 2);

    stack.pop();
    Test_MinInStack("Test6", stack, 3);

    stack.pop();
    Test_MinInStack("Test7", stack, 3);

    stack.push(0);
    Test_MinInStack("Test8", stack, 0);

}