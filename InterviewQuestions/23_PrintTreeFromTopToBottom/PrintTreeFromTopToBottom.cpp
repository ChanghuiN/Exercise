//
// Created by ChanghuiN on 2018/1/4.
//

#include <cstdlib>
#include <cstdio>
#include <deque>
#include "PrintTreeFromTopToBottom.h"


void PrintFromTopToBottom(BinaryTreeNode *pRoot) {

    if(pRoot == NULL)
        return;

    std::deque<BinaryTreeNode *> dequeTreeNode;
    dequeTreeNode.push_back(pRoot);

    while (dequeTreeNode.size() > 0) {

        BinaryTreeNode *pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();

        printf("%d ", pNode->m_nValue);

        if (pNode->m_pLeft != NULL)
            dequeTreeNode.push_back(pNode->m_pLeft);
        if (pNode->m_pRight != NULL)
            dequeTreeNode.push_back(pNode->m_pRight);
    }
}

void Test_PrintTreeFromTopToBottom(char *testName, BinaryTreeNode *pRoot) {

    if(testName != NULL)
        printf("%s begins: \n", testName);

    PrintTree(pRoot);

    printf("The nodes from top to bottom, from left to right are: \n");
    PrintFromTopToBottom(pRoot);

    printf("\n\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1_PrintTreeFromTopToBottom() {
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

    Test_PrintTreeFromTopToBottom("Test1", pNode10);

    DestroyTree(pNode10);
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
void Test2_PrintTreeFromTopToBottom() {
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode2, NULL);
    ConnectTreeNodes(pNode2, pNode1, NULL);

    Test_PrintTreeFromTopToBottom("Test2", pNode5);

    DestroyTree(pNode5);
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
void Test3_PrintTreeFromTopToBottom() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, NULL, pNode2);
    ConnectTreeNodes(pNode2, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode5);

    Test_PrintTreeFromTopToBottom("Test3", pNode1);

    DestroyTree(pNode1);
}

// 树中只有1个结点
void Test4_PrintTreeFromTopToBottom() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    Test_PrintTreeFromTopToBottom("Test4", pNode1);

    DestroyTree(pNode1);
}

// 树中没有结点
void Test5_PrintTreeFromTopToBottom() {
    Test_PrintTreeFromTopToBottom("Test5", NULL);
}

void Test_23_PrintTreeFromTopToBottom() {

    Test1_PrintTreeFromTopToBottom();
    Test2_PrintTreeFromTopToBottom();
    Test3_PrintTreeFromTopToBottom();
    Test4_PrintTreeFromTopToBottom();
    Test5_PrintTreeFromTopToBottom();
}