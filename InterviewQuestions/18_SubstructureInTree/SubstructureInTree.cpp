//
// Created by ChanghuiN on 2018/1/4.
//

#include <cstdio>
#include "SubstructureInTree.h"

// 判断相同结点
bool HasSubtree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2) {
    bool result = false;

    if (pRoot1 != NULL && pRoot2 != NULL) {
        if (pRoot1->m_nValue == pRoot2->m_nValue)
            result = DoesTree1HaveTree2(pRoot1, pRoot2);
        if (!result)
            result = HasSubtree(pRoot1->m_pLeft, pRoot2);
        if(!result)
            result = HasSubtree(pRoot1->m_pRight, pRoot2);
    }
    return result;
}

// 判断内容相同
bool DoesTree1HaveTree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2) {
    if (pRoot2 == NULL)
        return true;
    if (pRoot1 == NULL)
        return false;
    if (pRoot1->m_nValue != pRoot2->m_nValue)
        return false;

    return DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight) &&
           DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft);
}

void Test_SubstructureInTree(char *testName, BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2, bool expected) {

    if(HasSubtree(pRoot1, pRoot2) == expected)
        printf("%s passed.\n", testName);
    else
        printf("%s failed.\n", testName);
}

// 树中结点含有分叉，树B是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7
void Test1_SubstructureInTree() {
    BinaryTreeNode *pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeA3 = CreateBinaryTreeNode(7);
    BinaryTreeNode *pNodeA4 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNodeA5 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNodeA6 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNodeA7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
    ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
    ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

    BinaryTreeNode *pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNodeB3 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

    Test_SubstructureInTree("Test1", pNodeA1, pNodeB1, true);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// 树中结点含有分叉，树B不是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     3
//               / \
//              4   7
void Test2_SubstructureInTree() {
    BinaryTreeNode *pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeA3 = CreateBinaryTreeNode(7);
    BinaryTreeNode *pNodeA4 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNodeA5 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNodeA6 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNodeA7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
    ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
    ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

    BinaryTreeNode *pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNodeB3 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

    Test_SubstructureInTree("Test2", pNodeA1, pNodeB1, false);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// 树中结点只有左子结点，树B是树A的子结构
//                8                  8
//              /                   /
//             8                   9
//           /                    /
//          9                    2
//         /
//        2
//       /
//      5
void Test3_SubstructureInTree() {
    BinaryTreeNode *pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeA3 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNodeA4 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNodeA5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNodeA1, pNodeA2, NULL);
    ConnectTreeNodes(pNodeA2, pNodeA3, NULL);
    ConnectTreeNodes(pNodeA3, pNodeA4, NULL);
    ConnectTreeNodes(pNodeA4, pNodeA5, NULL);

    BinaryTreeNode *pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNodeB3 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, pNodeB2, NULL);
    ConnectTreeNodes(pNodeB2, pNodeB3, NULL);

    Test_SubstructureInTree("Test3", pNodeA1, pNodeB1, true);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// 树中结点只有左子结点，树B不是树A的子结构
//                8                  8
//              /                   /
//             8                   9
//           /                    /
//          9                    3
//         /
//        2
//       /
//      5
void Test4_SubstructureInTree() {
    BinaryTreeNode *pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeA3 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNodeA4 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNodeA5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNodeA1, pNodeA2, NULL);
    ConnectTreeNodes(pNodeA2, pNodeA3, NULL);
    ConnectTreeNodes(pNodeA3, pNodeA4, NULL);
    ConnectTreeNodes(pNodeA4, pNodeA5, NULL);

    BinaryTreeNode *pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNodeB3 = CreateBinaryTreeNode(3);

    ConnectTreeNodes(pNodeB1, pNodeB2, NULL);
    ConnectTreeNodes(pNodeB2, pNodeB3, NULL);

    Test_SubstructureInTree("Test4", pNodeA1, pNodeB1, false);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// 树中结点只有右子结点，树B是树A的子结构
//       8                   8
//        \                   \
//         8                   9
//          \                   \
//           9                   2
//            \
//             2
//              \
//               5
void Test5_SubstructureInTree() {
    BinaryTreeNode *pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeA3 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNodeA4 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNodeA5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNodeA1, NULL, pNodeA2);
    ConnectTreeNodes(pNodeA2, NULL, pNodeA3);
    ConnectTreeNodes(pNodeA3, NULL, pNodeA4);
    ConnectTreeNodes(pNodeA4, NULL, pNodeA5);

    BinaryTreeNode *pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNodeB3 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, NULL, pNodeB2);
    ConnectTreeNodes(pNodeB2, NULL, pNodeB3);

    Test_SubstructureInTree("Test5", pNodeA1, pNodeB1, true);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// 树A中结点只有右子结点，树B不是树A的子结构
//       8                   8
//        \                   \
//         8                   9
//          \                 / \
//           9               3   2
//            \
//             2
//              \
//               5
void Test6_SubstructureInTree() {
    BinaryTreeNode *pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeA3 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNodeA4 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNodeA5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNodeA1, NULL, pNodeA2);
    ConnectTreeNodes(pNodeA2, NULL, pNodeA3);
    ConnectTreeNodes(pNodeA3, NULL, pNodeA4);
    ConnectTreeNodes(pNodeA4, NULL, pNodeA5);

    BinaryTreeNode *pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNodeB3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNodeB4 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, NULL, pNodeB2);
    ConnectTreeNodes(pNodeB2, pNodeB3, pNodeB4);

    Test_SubstructureInTree("Test6", pNodeA1, pNodeB1, false);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// 树A为空树
void Test7_SubstructureInTree() {
    BinaryTreeNode *pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNodeB3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNodeB4 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, NULL, pNodeB2);
    ConnectTreeNodes(pNodeB2, pNodeB3, pNodeB4);

    Test_SubstructureInTree("Test7", NULL, pNodeB1, false);

    DestroyTree(pNodeB1);
}

// 树B为空树
void Test8_SubstructureInTree() {
    BinaryTreeNode *pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNodeA2 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNodeA3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNodeA4 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeA1, NULL, pNodeA2);
    ConnectTreeNodes(pNodeA2, pNodeA3, pNodeA4);

    Test_SubstructureInTree("Test8", pNodeA1, NULL, false);

    DestroyTree(pNodeA1);
}

// 树A和树B都为空
void Test9_SubstructureInTree() {
    Test_SubstructureInTree("Test9", NULL, NULL, false);
}

void Test_18_SubstructureInTree() {

    Test1_SubstructureInTree();
    Test2_SubstructureInTree();
    Test3_SubstructureInTree();
    Test4_SubstructureInTree();
    Test5_SubstructureInTree();
    Test6_SubstructureInTree();
    Test7_SubstructureInTree();
    Test8_SubstructureInTree();
    Test9_SubstructureInTree();
}
