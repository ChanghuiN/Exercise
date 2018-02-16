//
// Created by changhuin on 18-1-6.
//

// 两个链表的第一公共点
#ifndef EXERCISE_FIRSTCOMMANDNODESINLISTS_H
#define EXERCISE_FIRSTCOMMANDNODESINLISTS_H


#include "../Utilities/List.h"


unsigned int GetListLength(ListNode* pHead);

ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2);

void Test_FirstCommandNodesInLists(char* testName, ListNode* pHead1, ListNode* pHead2, ListNode* pExpected);

void Test_37_FirstCommandNodesInLists();

#endif //EXERCISE_FIRSTCOMMANDNODESINLISTS_H
