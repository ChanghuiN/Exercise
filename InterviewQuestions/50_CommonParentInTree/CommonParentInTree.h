//
// Created by ChanghuiN on 2018/1/10.
//

// 树中两个结点的最低公共祖先
#ifndef EXERCISE_COMMONPARENTINTREE_H
#define EXERCISE_COMMONPARENTINTREE_H


#include "../Utilities/Tree.h"
#include <list>


bool GetNodePath(TreeNode* pRoot, TreeNode* pNode, std::list<TreeNode*>& path);

TreeNode* GetLastCommonNode(const std::list<TreeNode*>& path1, const std::list<TreeNode*>& path2);

TreeNode* GetLastCommonParent(TreeNode* pRoot, TreeNode* pNode1, TreeNode* pNode2);

void Test_CommonParentInTree(char* testName, TreeNode* pRoot, TreeNode* pNode1, TreeNode* pNode2, TreeNode* pExpected);

void Test_50_CommonParentInTree();

#endif //EXERCISE_COMMONPARENTINTREE_H
