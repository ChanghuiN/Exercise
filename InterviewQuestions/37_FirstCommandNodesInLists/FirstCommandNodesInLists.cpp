//
// Created by changhuin on 18-1-6.
//

#include <cstdio>
#include "FirstCommandNodesInLists.h"


ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {

    // 得到两个链表的长度
    unsigned int nLength1 = GetListLength(pHead1);
    unsigned int nLength2 = GetListLength(pHead2);
    int nLengthDif = nLength1 - nLength2;

    ListNode *pListHeadLong = pHead1;
    ListNode *pListHeadShort = pHead2;
    if (nLength2 > nLength1) {
        pListHeadLong = pHead2;
        pListHeadShort = pHead1;
        nLengthDif = nLength2 - nLength1;
    }

    // 先在长链表上走几步，再同时在两个链表上遍历
    for (int i = 0; i < nLengthDif; ++i)
        pListHeadLong = pListHeadLong->m_pNext;

    while ((pListHeadLong != NULL) && (pListHeadShort != NULL) && (pListHeadLong != pListHeadShort)) {
        pListHeadLong = pListHeadLong->m_pNext;
        pListHeadShort = pListHeadShort->m_pNext;
    }

    return pListHeadLong;
}

unsigned int GetListLength(ListNode *pHead) {
    unsigned int nLength = 0;
    ListNode *pNode = pHead;
    while (pNode != NULL) {
        nLength++;
        pNode = pNode->m_pNext;
    }
    return nLength;
}

void Test_FirstCommandNodesInLists(char *testName, ListNode *pHead1, ListNode *pHead2, ListNode *pExpected) {

    if (testName != NULL)
        printf("%s begins: ", testName);

    ListNode *pResult = FindFirstCommonNode(pHead1, pHead2);
    if (pResult == pExpected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void DestroyNode_FirstCommandNodesInLists(ListNode *pNode) {
    delete pNode;
    pNode = NULL;
}

// 第一个公共结点在链表中间
// 1 - 2 - 3 \
//            6 - 7
//     4 - 5 /
void Test1_FirstCommandNodesInLists() {
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);
    ListNode *pNode6 = CreateListNode(6);
    ListNode *pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode6);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    Test_FirstCommandNodesInLists("Test1", pNode1, pNode4, pNode6);

    DestroyNode_FirstCommandNodesInLists(pNode1);
    DestroyNode_FirstCommandNodesInLists(pNode2);
    DestroyNode_FirstCommandNodesInLists(pNode3);
    DestroyNode_FirstCommandNodesInLists(pNode4);
    DestroyNode_FirstCommandNodesInLists(pNode5);
    DestroyNode_FirstCommandNodesInLists(pNode6);
    DestroyNode_FirstCommandNodesInLists(pNode7);
}

// 没有公共结点
// 1 - 2 - 3 - 4
//
// 5 - 6 - 7
void Test2_FirstCommandNodesInLists() {
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);
    ListNode *pNode6 = CreateListNode(6);
    ListNode *pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    Test_FirstCommandNodesInLists("Test2", pNode1, pNode5, NULL);

    DestroyList(pNode1);
    DestroyList(pNode5);
}

// 公共结点是最后一个结点
// 1 - 2 - 3 - 4 \
//                7
//         5 - 6 /
void Test3_FirstCommandNodesInLists() {
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);
    ListNode *pNode6 = CreateListNode(6);
    ListNode *pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode7);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    Test_FirstCommandNodesInLists("Test3", pNode1, pNode5, pNode7);

    DestroyNode_FirstCommandNodesInLists(pNode1);
    DestroyNode_FirstCommandNodesInLists(pNode2);
    DestroyNode_FirstCommandNodesInLists(pNode3);
    DestroyNode_FirstCommandNodesInLists(pNode4);
    DestroyNode_FirstCommandNodesInLists(pNode5);
    DestroyNode_FirstCommandNodesInLists(pNode6);
    DestroyNode_FirstCommandNodesInLists(pNode7);
}

// 公共结点是第一个结点
// 1 - 2 - 3 - 4 - 5
// 两个链表完全重合
void Test4_FirstCommandNodesInLists() {
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test_FirstCommandNodesInLists("Test4", pNode1, pNode1, pNode1);

    DestroyList(pNode1);
}

// 输入的两个链表有一个空链表
void Test5_FirstCommandNodesInLists() {
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test_FirstCommandNodesInLists("Test5", NULL, pNode1, NULL);

    DestroyList(pNode1);
}

// 输入的两个链表有一个空链表
void Test6_FirstCommandNodesInLists() {
    Test_FirstCommandNodesInLists("Test6", NULL, NULL, NULL);
}

void Test_37_FirstCommandNodesInLists() {

    Test1_FirstCommandNodesInLists();
    Test2_FirstCommandNodesInLists();
    Test3_FirstCommandNodesInLists();
    Test4_FirstCommandNodesInLists();
    Test5_FirstCommandNodesInLists();
    Test6_FirstCommandNodesInLists();
}