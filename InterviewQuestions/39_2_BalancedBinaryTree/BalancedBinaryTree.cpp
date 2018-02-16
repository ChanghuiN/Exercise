//
// Created by changhuin on 18-1-6.
//

#include <cstdio>
#include "BalancedBinaryTree.h"


int TreeDepth2(BinaryTreeNode *pRoot) {

    if (pRoot == NULL)
        return 0;

    int nLeft = TreeDepth2(pRoot->m_pLeft);
    int nRight = TreeDepth2(pRoot->m_pRight);

    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

bool IsBalanced_Solution1(BinaryTreeNode *pRoot) {

    if (pRoot == NULL)
        return true;

    int left = TreeDepth2(pRoot->m_pLeft);
    int right = TreeDepth2(pRoot->m_pRight);
    int diff = left - right;
    if (diff > 1 || diff < -1)
        return false;

    return IsBalanced_Solution1(pRoot->m_pLeft) && IsBalanced_Solution1(pRoot->m_pRight);
}

bool IsBalanced(BinaryTreeNode *pRoot, int *pDepth) {
    if (pRoot == NULL) {
        *pDepth = 0;
        return true;
    }

    int left, right;
    if (IsBalanced(pRoot->m_pLeft, &left) && IsBalanced(pRoot->m_pRight, &right)) {
        int diff = left - right;
        if (diff <= 1 && diff >= -1) {
            *pDepth = 1 + (left > right ? left : right);
            return true;
        }
    }
    return false;
}

bool IsBalanced_Solution2(BinaryTreeNode *pRoot) {

    int depth = 0;
    return IsBalanced(pRoot, &depth);
}

void Test_BalancedBinaryTree(char *testName, BinaryTreeNode *pRoot, bool expected) {

    if (testName != NULL)
        printf("%s begins:\n", testName);

    printf("Solution1 begins: ");
    if (IsBalanced_Solution1(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Solution2 begins: ");
    if (IsBalanced_Solution2(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 完全二叉树
//             1
//         /      \
//        2        3
//       /\       / \
//      4  5     6   7
void Test1_BalancedBinaryTree() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode3, pNode6, pNode7);

    Test_BalancedBinaryTree("Test1", pNode1, true);

    DestroyTree(pNode1);
}

// 不是完全二叉树，但是平衡二叉树
//             1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
void Test2_BalancedBinaryTree() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode3, NULL, pNode6);
    ConnectTreeNodes(pNode5, pNode7, NULL);

    Test_BalancedBinaryTree("Test2", pNode1, true);

    DestroyTree(pNode1);
}

// 不是平衡二叉树
//             1
//         /      \
//        2        3
//       /\
//      4  5
//        /
//       6
void Test3_BalancedBinaryTree() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);

    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode5, pNode6, NULL);

    Test_BalancedBinaryTree("Test3", pNode1, false);

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
void Test4_BalancedBinaryTree() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2, NULL);
    ConnectTreeNodes(pNode2, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode5, NULL);

    Test_BalancedBinaryTree("Test4", pNode1, false);

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
void Test5_BalancedBinaryTree() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, NULL, pNode2);
    ConnectTreeNodes(pNode2, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode5);

    Test_BalancedBinaryTree("Test5", pNode1, false);

    DestroyTree(pNode1);
}

// 树中只有1个结点
void Test6_BalancedBinaryTree() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    Test_BalancedBinaryTree("Test6", pNode1, true);

    DestroyTree(pNode1);
}

// 树中没有结点
void Test7_BalancedBinaryTree() {
    Test_BalancedBinaryTree("Test7", NULL, true);
}

void Test_39_2_BalancedBinaryTree() {

    Test1_BalancedBinaryTree();
    Test2_BalancedBinaryTree();
    Test3_BalancedBinaryTree();
    Test4_BalancedBinaryTree();
    Test5_BalancedBinaryTree();
    Test6_BalancedBinaryTree();
    Test7_BalancedBinaryTree();
}