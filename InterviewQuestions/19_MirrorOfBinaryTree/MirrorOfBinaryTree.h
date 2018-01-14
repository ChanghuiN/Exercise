//
// Created by ChanghuiN on 2018/1/4.
//

// 二叉树的镜像
#ifndef EXERCISE_MIRROROFBINARYTREE_H
#define EXERCISE_MIRROROFBINARYTREE_H


#include "../Utilities/BinaryTree.h"

// 通过递归实现
void MirrorRecursively(BinaryTreeNode *pNode);

// 使用栈遍历的方式实现
void MirrorIteratively(BinaryTreeNode* pRoot);

void Test_19_MirrorOfBinaryTree();

#endif //EXERCISE_MIRROROFBINARYTREE_H
