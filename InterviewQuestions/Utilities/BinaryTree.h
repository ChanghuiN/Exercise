//
// Created by ChanghuiN on 2017/11/15.
//
struct BinaryTreeNode
{
    int                    m_nValue;
    BinaryTreeNode*        m_pLeft;
    BinaryTreeNode*        m_pRight;
};

BinaryTreeNode* CreateBinaryTreeNode(int value);
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
void PrintTreeNode(BinaryTreeNode* pNode);
void PrintTree(BinaryTreeNode* pRoot);
void DestroyTree(BinaryTreeNode* pRoot);
