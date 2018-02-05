//
// Created by ChanghuiN on 2018/1/5.
//

#include <cstdio>
#include "ConvertBinarySearchTree.h"


//
BinaryTreeNode *Convert(BinaryTreeNode *pRootOfTree) {

    BinaryTreeNode *pLastNodeInList = NULL;
    ConvertNode(pRootOfTree, &pLastNodeInList);

    // pLastNodeInList指向双向链表的尾结点，
    // 我们需要返回头结点
    BinaryTreeNode *pHeadOfList = pLastNodeInList;
    while(pHeadOfList != NULL && pHeadOfList->m_pLeft != NULL)
        pHeadOfList = pHeadOfList->m_pLeft;

    return pHeadOfList;
}

// 递归
void ConvertNode(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeInList) {
    if (pNode == NULL)
        return;

    BinaryTreeNode *pCurrent = pNode;

    if (pCurrent->m_pLeft != NULL)
        ConvertNode(pCurrent->m_pLeft, pLastNodeInList);

    pCurrent->m_pLeft = *pLastNodeInList;
    if (*pLastNodeInList != NULL)
        (*pLastNodeInList)->m_pRight = pCurrent;
    *pLastNodeInList = pCurrent;

    if (pCurrent->m_pRight != NULL)
        ConvertNode(pCurrent->m_pRight, pLastNodeInList);
}

void PrintDoubleLinkedList(BinaryTreeNode *pHeadOfList) {
    BinaryTreeNode *pNode = pHeadOfList;

    printf("The nodes from left to right are:\n");
    while (pNode != NULL) {
        printf("%d\t", pNode->m_nValue);

        if (pNode->m_pRight == NULL)
            break;
        pNode = pNode->m_pRight;
    }

    printf("\nThe nodes from right to left are:\n");
    while (pNode != NULL) {
        printf("%d\t", pNode->m_nValue);

        if (pNode->m_pLeft == NULL)
            break;
        pNode = pNode->m_pLeft;
    }

    printf("\n");
}

void DestroyList(BinaryTreeNode *pHeadOfList) {
    BinaryTreeNode *pNode = pHeadOfList;
    while (pNode != NULL) {
        BinaryTreeNode *pNext = pNode->m_pRight;

        delete pNode;
        pNode = pNext;
    }
}

void Test_ConvertBinarySearchTree(char *testName, BinaryTreeNode *pRootOfTree) {

    if (testName != NULL)
        printf("%s begins:\n", testName);

    PrintTree(pRootOfTree);

    BinaryTreeNode *pHeadOfList = Convert(pRootOfTree);

    PrintDoubleLinkedList(pHeadOfList);
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1_ConvertBinarySearchTree() {
    BinaryTreeNode *pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode *pNode16 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

    Test_ConvertBinarySearchTree("Test1", pNode10);

    DestroyList(pNode4);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test2_ConvertBinarySearchTree() {
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode2, NULL);
    ConnectTreeNodes(pNode2, pNode1, NULL);

    Test_ConvertBinarySearchTree("Test2", pNode5);

    DestroyList(pNode1);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test3_ConvertBinarySearchTree() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, NULL, pNode2);
    ConnectTreeNodes(pNode2, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode5);

    Test_ConvertBinarySearchTree("Test3", pNode1);

    DestroyList(pNode1);
}

// 树中只有1个结点
void Test4_ConvertBinarySearchTree() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    Test_ConvertBinarySearchTree("Test4", pNode1);

    DestroyList(pNode1);
}

// 树中没有结点
void Test5_ConvertBinarySearchTree() {
    Test_ConvertBinarySearchTree("Test5", NULL);
}

void Test_27_ConvertBinarySearchTree() {

    Test1_ConvertBinarySearchTree();
    Test2_ConvertBinarySearchTree();
    Test3_ConvertBinarySearchTree();
    Test4_ConvertBinarySearchTree();
    Test5_ConvertBinarySearchTree();
}