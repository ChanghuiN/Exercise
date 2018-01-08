//
// Created by ChanghuiN on 2018/1/4.
//

// 根据前序遍历、中序遍历重建二叉树
#ifndef EXERCISE_CONSTRUCTBINARYTREE_H
#define EXERCISE_CONSTRUCTBINARYTREE_H


#include "../Utilities/BinaryTree.h"

/**
 *
 * @param preorder 前序遍历
 * @param inorder  中序遍历
 * @param length   长度
 * @return
 */
BinaryTreeNode *Construct(int *preorder, int *inorder, int length);

BinaryTreeNode *ConstructCore
        (
                int *startPreorder, int *endPreorder,
                int *startInorder, int *endInorder
        );

void Test_ConstructBinaryTree(char *testName, int *preorder, int *inorder, int length);

void Test_6_ConstructBinaryTree();


#endif //EXERCISE_CONSTRUCTBINARYTREE_H
