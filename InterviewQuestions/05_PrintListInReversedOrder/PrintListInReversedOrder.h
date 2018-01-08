//
// Created by ChanghuiN on 17-11-15.
//

// 倒序打印链表
#ifndef EXERCISE_PRINTLISTINREVERSEDORDER_H
#define EXERCISE_PRINTLISTINREVERSEDORDER_H

#include "../Utilities/List.h"

// 将链表保存栈中，之后出栈
void PrintListReversingly_Iteratively(ListNode* pHead);

// 使用递归方法，
void PrintListReversingly_Recursively(ListNode* pHead);

void Test_PrintListReversed(ListNode* pHead);

void Test_5_PrintListReversed();

#endif //EXERCISE_PRINTLISTINREVERSEDORDER_H
