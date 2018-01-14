//
// Created by ChanghuiN on 2018/1/4.
//

// 在O(1)时间删除链表结点
#ifndef EXERCISE_DELETENODEINLIST_H
#define EXERCISE_DELETENODEINLIST_H


#include "../Utilities/List.h"


void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted);

void Test_DeleteNodeInList(ListNode* pListHead, ListNode* pNode);

void Test_13_DeleteNodeInList();

#endif //EXERCISE_DELETENODEINLIST_H
