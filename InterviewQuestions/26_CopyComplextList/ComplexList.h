//
// Created by ChanghuiN on 2018/1/5.
//

#ifndef EXERCISE_COMPLEXLIST_H
#define EXERCISE_COMPLEXLIST_H


struct ComplexListNode {
    int m_nValue;
    ComplexListNode *m_pNext;
    ComplexListNode *m_pSibling;
};

ComplexListNode *CreateNode(int nValue);

void BuildNodes(ComplexListNode *pNode, ComplexListNode *pNext, ComplexListNode *pSibling);

void PrintList(ComplexListNode *pHead);


#endif //EXERCISE_COMPLEXLIST_H
