//
// Created by ChanghuiN on 2018/1/4.
//

#include <cstdio>
#include "MergeSortedLists.h"


ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
    if (pHead1 == NULL)
        return pHead2;
    if (pHead2 == NULL)
        return pHead1;

    ListNode *pHead = NULL;
    ListNode *pMergedHead = NULL;
    ListNode *pMergedHead1 = pHead1;
    ListNode *pMergedHead2 = pHead2;
    // 判断头结点
    if (pMergedHead1->m_nValue < pMergedHead2->m_nValue) {
        pHead = pMergedHead = pMergedHead1;
        pMergedHead1 = pMergedHead1->m_pNext;
    } else {
        pHead = pMergedHead = pMergedHead2;
        pMergedHead2 = pMergedHead2->m_pNext;
    }
    // 合并
    while (pMergedHead1 != NULL && pMergedHead2 != NULL) {
        if (pMergedHead1->m_nValue < pMergedHead2->m_nValue) {
            pMergedHead->m_pNext = pMergedHead1;
            pMergedHead = pMergedHead1;
            pMergedHead1 = pMergedHead1->m_pNext;
        } else {
            pMergedHead->m_pNext = pMergedHead2;
            pMergedHead = pMergedHead2;
            pMergedHead2 = pMergedHead2->m_pNext;
        }
    }
    // 合并不是null的
    if (pMergedHead1 != NULL)
        pMergedHead->m_pNext = pMergedHead1;
    if (pMergedHead2 != NULL)
        pMergedHead->m_pNext = pMergedHead2;
    return pHead;
}

ListNode *Test_MergeSortedLists(char *testName, ListNode *pHead1, ListNode *pHead2) {
    if (testName != NULL)
        printf("%s begins:\n", testName);

    printf("The first list is:\n");
    PrintList(pHead1);

    printf("The second list is:\n");
    PrintList(pHead2);

    printf("The merged list is:\n");
    ListNode *pMergedHead = Merge(pHead1, pHead2);
    PrintList(pMergedHead);

    printf("\n\n");

    return pMergedHead;
}

// list1: 1->3->5
// list2: 2->4->6
void Test1_MergeSortedLists() {
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode6 = CreateListNode(6);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode *pMergedHead = Test_MergeSortedLists("Test1", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 两个链表中有重复的数字
// list1: 1->3->5
// list2: 1->3->5
void Test2_MergeSortedLists() {
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode *pNode2 = CreateListNode(1);
    ListNode *pNode4 = CreateListNode(3);
    ListNode *pNode6 = CreateListNode(5);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode *pMergedHead = Test_MergeSortedLists("Test2", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 两个链表都只有一个数字
// list1: 1
// list2: 2
void Test3_MergeSortedLists() {
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);

    ListNode *pMergedHead = Test_MergeSortedLists("Test3", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 一个链表为空链表
// list1: 1->3->5
// list2: 空链表
void Test4_MergeSortedLists() {
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode *pMergedHead = Test_MergeSortedLists("Test4", pNode1, NULL);

    DestroyList(pMergedHead);
}

// 两个链表都为空链表
// list1: 空链表
// list2: 空链表
void Test5_MergeSortedLists() {
    ListNode *pMergedHead = Test_MergeSortedLists("Test5", NULL, NULL);
}


void Test_17_MergeSortedLists() {

    Test1_MergeSortedLists();
    Test2_MergeSortedLists();
    Test3_MergeSortedLists();
    Test4_MergeSortedLists();
    Test5_MergeSortedLists();
}