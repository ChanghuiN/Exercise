//
// Created by ChanghuiN on 2018/1/4.
//

// 二叉树中和为某一值的路径
#ifndef EXERCISE_PATHINTREE_H
#define EXERCISE_PATHINTREE_H


#include <vector>
#include "../Utilities/BinaryTree.h"


void FindPath(BinaryTreeNode *pRoot, int expectedSum);

void FindPath(BinaryTreeNode *pRoot, int expectedSum, std::vector<int> &path, int &currentSum);

void Test_PathInTree(char *testName, BinaryTreeNode *pRoot, int expectedSum);

void Test_25_PathInTree();

#endif //EXERCISE_PATHINTREE_H
