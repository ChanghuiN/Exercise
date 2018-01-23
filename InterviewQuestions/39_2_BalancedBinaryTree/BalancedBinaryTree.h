//
// Created by changhuin on 18-1-6.
//

// 判断二叉树是否为平衡二叉树
#ifndef EXERCISE_BALANCEDBINARYTREE_H
#define EXERCISE_BALANCEDBINARYTREE_H


#include "../Utilities/BinaryTree.h"


int TreeDepth2(BinaryTreeNode* pRoot);

bool IsBalanced_Solution1(BinaryTreeNode* pRoot);

bool IsBalanced(BinaryTreeNode* pRoot, int* pDepth);

bool IsBalanced_Solution2(BinaryTreeNode* pRoot);

void Test_BalancedBinaryTree(char* testName, BinaryTreeNode* pRoot, bool expected);

void Test_39_2_BalancedBinaryTree();

#endif //EXERCISE_BALANCEDBINARYTREE_H
