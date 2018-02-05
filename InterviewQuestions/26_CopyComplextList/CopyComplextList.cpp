//
// Created by changhuin on 18-1-17.
//

#include <cstdlib>
#include <cstdio>
#include "CopyComplextList.h"


// 复制函数
ComplexListNode *Clone(ComplexListNode *pHead) {

    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}

// 复制结点
void CloneNodes(ComplexListNode *pHead) {

    ComplexListNode *pNode = pHead;
    while (pNode != NULL) {
        ComplexListNode *pCloned = CreateNode(pNode->m_nValue);
        BuildNodes(pCloned, pNode->m_pNext, NULL);

        pNode->m_pNext = pCloned;
        pNode = pCloned->m_pNext;
    }
}

// 复制另一个结点
void ConnectSiblingNodes(ComplexListNode *pHead) {
    ComplexListNode *pNode = pHead;
    while (pNode != NULL) {
        ComplexListNode *pCloned = pNode->m_pNext;
        if (pNode->m_pSibling != NULL) {
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
        }

        pNode = pCloned->m_pNext;
    }
}

// 删除奇数节点
ComplexListNode *ReconnectNodes(ComplexListNode *pHead) {

    ComplexListNode *pNode = pHead;
    ComplexListNode *pClonedHead = NULL;
    ComplexListNode *pClonedNode = NULL;

    if (pNode != NULL) {
        pClonedHead = pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    while (pNode != NULL) {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;

        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    return pClonedHead;
}

void Test_CopyComplextList(char *testName, ComplexListNode *pHead) {

    if (testName != NULL)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    PrintList(pHead);

    ComplexListNode *pClonedHead = Clone(pHead);

    printf("The cloned list is:\n");
    PrintList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1_CopyComplextList() {
    ComplexListNode *pNode1 = CreateNode(1);
    ComplexListNode *pNode2 = CreateNode(2);
    ComplexListNode *pNode3 = CreateNode(3);
    ComplexListNode *pNode4 = CreateNode(4);
    ComplexListNode *pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, NULL);
    BuildNodes(pNode4, pNode5, pNode2);

    Test_CopyComplextList("Test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2_CopyComplextList() {
    ComplexListNode *pNode1 = CreateNode(1);
    ComplexListNode *pNode2 = CreateNode(2);
    ComplexListNode *pNode3 = CreateNode(3);
    ComplexListNode *pNode4 = CreateNode(4);
    ComplexListNode *pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, NULL);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, pNode3);
    BuildNodes(pNode4, pNode5, pNode2);

    Test_CopyComplextList("Test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3_CopyComplextList() {
    ComplexListNode *pNode1 = CreateNode(1);
    ComplexListNode *pNode2 = CreateNode(2);
    ComplexListNode *pNode3 = CreateNode(3);
    ComplexListNode *pNode4 = CreateNode(4);
    ComplexListNode *pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, NULL);
    BuildNodes(pNode2, pNode3, pNode4);
    BuildNodes(pNode3, pNode4, NULL);
    BuildNodes(pNode4, pNode5, pNode2);

    Test_CopyComplextList("Test3", pNode1);
}

// 只有一个结点
void Test4_CopyComplextList() {
    ComplexListNode *pNode1 = CreateNode(1);
    BuildNodes(pNode1, NULL, pNode1);

    Test_CopyComplextList("Test4", pNode1);
}

// 鲁棒性测试
void Test5_CopyComplextList() {
    Test_CopyComplextList("Test5", NULL);
}

void Test_26_CopyComplextList() {

    Test1_CopyComplextList();
    Test2_CopyComplextList();
    Test3_CopyComplextList();
    Test4_CopyComplextList();
    Test5_CopyComplextList();
}
