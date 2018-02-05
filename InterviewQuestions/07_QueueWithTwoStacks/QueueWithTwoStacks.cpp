//
// Created by ChanghuiN on 2018/1/4.
//

#include <cstdio>
#include "QueueWithTwoStacks.h"
#include "Queue.h"


void Test_QueueWithTwoStacks(char actual, char expected){
    if(actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

void Test_7_QueueWithTwoStacks() {

    CQueue<char> queue;

    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
    Test_QueueWithTwoStacks(head, 'a');

    head = queue.deleteHead();
    Test_QueueWithTwoStacks(head, 'b');

    queue.appendTail('d');
    head = queue.deleteHead();
    Test_QueueWithTwoStacks(head, 'c');

    queue.appendTail('e');
    head = queue.deleteHead();
    Test_QueueWithTwoStacks(head, 'd');

    head = queue.deleteHead();
    Test_QueueWithTwoStacks(head, 'e');
}