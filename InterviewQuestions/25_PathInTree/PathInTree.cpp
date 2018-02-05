//
// Created by ChanghuiN on 2018/1/4.
//

#include <cstdlib>
#include <cstdio>
#include "PathInTree.h"


void FindPath(BinaryTreeNode *pRoot, int expectedSum) {

}

void FindPath(BinaryTreeNode *pRoot, int expectedSum, std::vector<int> &path, int &currentSum) {

}

void Test_PathInTree(char *testName, BinaryTreeNode *pRoot, int expectedSum) {

    if (testName != NULL)
        printf("%s begins:\n", testName);

    FindPath(pRoot, expectedSum);

    printf("\n");
}

//            10
//         /      \
//        5        12
//       /\
//      4  7
// 有两条路径上的结点和为22
void Test1_PathInTree() {
    BinaryTreeNode *pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    printf("Two paths should be found in Test1.\n");
    Test_PathInTree("Test1", pNode10, 22);

    DestroyTree(pNode10);
}

//            10
//         /      \
//        5        12
//       /\
//      4  7
// 没有路径上的结点和为15
void Test2_PathInTree() {
    BinaryTreeNode *pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    printf("No paths should be found in Test2.\n");
    Test_PathInTree("Test2", pNode10, 15);

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
// 有一条路径上面的结点和为15
void Test3_PathInTree() {
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode2, NULL);
    ConnectTreeNodes(pNode2, pNode1, NULL);

    printf("One path should be found in Test3.\n");
    Test_PathInTree("Test3", pNode5, 15);

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
// 没有路径上面的结点和为16
void Test4_PathInTree() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, NULL, pNode2);
    ConnectTreeNodes(pNode2, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode5);

    printf("No paths should be found in Test4.\n");
    Test_PathInTree("Test4", pNode1, 16);

    DestroyTree(pNode1);
}

// 树中只有1个结点
void Test5_PathInTree() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);

    printf("One path should be found in Test5.\n");
    Test_PathInTree("Test5", pNode1, 1);

    DestroyTree(pNode1);
}

// 树中没有结点
void Test6_PathInTree() {
    printf("No paths should be found in Test6.\n");
    Test_PathInTree("Test6", NULL, 0);
}


void Test_25_PathInTree() {

    Test1_PathInTree();
    Test2_PathInTree();
    Test3_PathInTree();
    Test4_PathInTree();
    Test5_PathInTree();
    Test6_PathInTree();
}