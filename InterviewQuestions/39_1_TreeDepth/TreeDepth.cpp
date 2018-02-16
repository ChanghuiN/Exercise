//
// Created by changhuin on 18-1-6.
//

#include <cstdio>
#include "TreeDepth.h"


int TreeDepth(BinaryTreeNode* pRoot) {

    if(pRoot == NULL)
        return 0;

    int nLeft = TreeDepth(pRoot->m_pLeft);
    int nRight = TreeDepth(pRoot->m_pRight);

    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

void Test_TreeDepth(BinaryTreeNode* pRoot, int expected) {

    int result = TreeDepth(pRoot);
    if(expected == result)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

//            1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
void Test1_TreeDepth()
{
    printf("Test1 begins.\n");

    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode3, NULL, pNode6);
    ConnectTreeNodes(pNode5, pNode7, NULL);

    Test_TreeDepth(pNode1, 4);

    DestroyTree(pNode1);
}

//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test2_TreeDepth()
{
    printf("Test2 begins.\n");

    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2, NULL);
    ConnectTreeNodes(pNode2, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode5, NULL);

    Test_TreeDepth(pNode1, 5);

    DestroyTree(pNode1);
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
void Test3_TreeDepth()
{
    printf("Test3 begins.\n");

    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, NULL, pNode2);
    ConnectTreeNodes(pNode2, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode5);

    Test_TreeDepth(pNode1, 5);

    DestroyTree(pNode1);
}

// 树中只有1个结点
void Test4_TreeDepth()
{
    printf("Test4 begins.\n");

    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    Test_TreeDepth(pNode1, 1);

    DestroyTree(pNode1);
}

// 树中没有结点
void Test5_TreeDepth()
{
    printf("Test5 begins.\n");

    Test_TreeDepth(NULL, 0);
}

void Test_39_1_TreeDepth() {

    Test1_TreeDepth();
    Test2_TreeDepth();
    Test3_TreeDepth();
    Test4_TreeDepth();
    Test5_TreeDepth();
}