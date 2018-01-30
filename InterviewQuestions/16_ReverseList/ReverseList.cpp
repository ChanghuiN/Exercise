//
// Created by ChanghuiN on 2018/1/4.
//

#include <cstdio>
#include "ReverseList.h"

ListNode *ReverseList(ListNode *pHead) {

    ListNode* pReversedHead = NULL;
    ListNode* pNode = pHead;
    ListNode* pPrev = NULL;

    while (pNode != NULL) {
        ListNode* pNext = pNode->m_pNext;
        if (pNext != NULL)
            pReversedHead = pNext;
        pNode->m_pNext = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    return pReversedHead;
}

ListNode *Test_ReverseList(ListNode *pHead) {

    printf("The original list is: \n");
    PrintList(pHead);

    ListNode *pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// 输入的链表有多个结点
void Test1_ReverseList() {
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode *pReversedHead = Test_ReverseList(pNode1);

    DestroyList(pReversedHead);
}

// 输入的链表只有一个结点
void Test2_ReverseList() {
    ListNode *pNode1 = CreateListNode(1);

    ListNode *pReversedHead = Test_ReverseList(pNode1);

    DestroyList(pReversedHead);
}

// 输入空链表
void Test3_ReverseList() {
    Test_ReverseList(NULL);
}

void Test_16_ReverseList() {

    Test1_ReverseList();
    Test2_ReverseList();
    Test3_ReverseList();
}