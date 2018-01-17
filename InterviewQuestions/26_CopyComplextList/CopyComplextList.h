//
// Created by changhuin on 18-1-17.
//

// 复杂链表的复制
#ifndef EXERCISE_COPYCOMPLEXTLIST_H
#define EXERCISE_COPYCOMPLEXTLIST_H


#include "ComplexList.h"


// 复制函数
ComplexListNode* Clone(ComplexListNode* pHead);

// 复制结点
void CloneNodes(ComplexListNode* pHead);

// 复制另一个结点
void ConnectSiblingNodes(ComplexListNode* pHead);

// 删除奇数节点
ComplexListNode* ReconnectNodes(ComplexListNode* pHead);

void Test_CopyComplextList(char* testName, ComplexListNode* pHead);

void Test_26_CopyComplextList();


#endif //EXERCISE_COPYCOMPLEXTLIST_H
