//
// Created by ChanghuiN on 2018/1/4.
//


// 树的子结构
#ifndef EXERCISE_SUBSTRUCTUREINTREE_H
#define EXERCISE_SUBSTRUCTUREINTREE_H


#include "../Utilities/BinaryTree.h"


// 判断相同结点
bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

// 判断内容相同
bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

void Test_SubstructureInTree(char* testName, BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2, bool expected);

void Test_18_SubstructureInTree();

#endif //EXERCISE_SUBSTRUCTUREINTREE_H
