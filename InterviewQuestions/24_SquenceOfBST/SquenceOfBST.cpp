//
// Created by ChanghuiN on 2018/1/4.
//

#include <cstdlib>
#include <cstdio>
#include "SquenceOfBST.h"


bool VerifySquenceOfBST(int sequence[], int length) {

    if(sequence == NULL || length <= 0)
        return false;

    int root = sequence[length - 1];

    // 在二叉搜索树中左子树的结点小于根结点
    int i = 0;
    for (; i < length - 1; ++i) {
        if (sequence[i] > root)
            break;
    }

    // 在二叉搜索树中右子树的结点大于根结点
    int j = i;
    for (; j < length - 1; j++) {
        if (sequence[j] < root)
            return false;
    }

    // 判断左子树是不是二叉搜索树
    bool left = true;
    if(i > 0)
        left = VerifySquenceOfBST(sequence, i);

    // 判断右子树是不是二叉搜索树
    bool right = true;
    if(i < length - 1)
        right = VerifySquenceOfBST(sequence + i, length - i - 1);

    return (left && right);
}

void Test_SquenceOfBST(char *testName, int sequence[], int length, bool expected) {

    if (testName != NULL)
        printf("%s begins: ", testName);

    if (VerifySquenceOfBST(sequence, length) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1_SquenceOfBST() {
    int data[] = {4, 8, 6, 12, 16, 14, 10};
    Test_SquenceOfBST("Test1", data, sizeof(data) / sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2_SquenceOfBST() {
    int data[] = {4, 6, 7, 5};
    Test_SquenceOfBST("Test2", data, sizeof(data) / sizeof(int), true);
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
void Test3_SquenceOfBST() {
    int data[] = {1, 2, 3, 4, 5};
    Test_SquenceOfBST("Test3", data, sizeof(data) / sizeof(int), true);
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
void Test4_SquenceOfBST() {
    int data[] = {5, 4, 3, 2, 1};
    Test_SquenceOfBST("Test4", data, sizeof(data) / sizeof(int), true);
}

// 树中只有1个结点
void Test5_SquenceOfBST() {
    int data[] = {5};
    Test_SquenceOfBST("Test5", data, sizeof(data) / sizeof(int), true);
}

void Test6_SquenceOfBST() {
    int data[] = {7, 4, 6, 5};
    Test_SquenceOfBST("Test6", data, sizeof(data) / sizeof(int), false);
}

void Test7_SquenceOfBST() {
    int data[] = {4, 6, 12, 8, 16, 14, 10};
    Test_SquenceOfBST("Test7", data, sizeof(data) / sizeof(int), false);
}

void Test8_SquenceOfBST() {
    Test_SquenceOfBST("Test8", NULL, 0, false);
}

void Test_24_SquenceOfBST() {

    Test1_SquenceOfBST();
    Test2_SquenceOfBST();
    Test3_SquenceOfBST();
    Test4_SquenceOfBST();
    Test5_SquenceOfBST();
    Test6_SquenceOfBST();
    Test7_SquenceOfBST();
    Test8_SquenceOfBST();
}