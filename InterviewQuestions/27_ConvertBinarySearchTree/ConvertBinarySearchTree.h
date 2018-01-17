//
// Created by ChanghuiN on 2018/1/5.
//

// 二叉搜索树与双向链表
#ifndef EXERCISE_CONVERTBINARYSEARCHTREE_H
#define EXERCISE_CONVERTBINARYSEARCHTREE_H


#include "../Utilities/BinaryTree.h"


//
BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree);

// 递归
void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)

void Test_ConvertBinarySearchTree(char* testName, BinaryTreeNode* pRootOfTree);

void Test_27_ConvertBinarySearchTree();

#endif //EXERCISE_CONVERTBINARYSEARCHTREE_H
