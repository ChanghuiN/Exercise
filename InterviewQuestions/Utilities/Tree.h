//
// Created by ChanghuiN on 2018/1/4.
//
// 树
//


#include <vector>

struct TreeNode
{
    int                     m_nValue;
    std::vector<TreeNode*>   m_vChildren;
};

TreeNode* CreateTreeNode(int value);
void ConnectTreeNodes(TreeNode* pParent, TreeNode* pChild);
void PrintTreeNode(TreeNode* pNode);
void PrintTree(TreeNode* pRoot);
void DestroyTree(TreeNode* pRoot);