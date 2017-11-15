//
// Created by ChanghuiN on 17-11-15.
//

#include "PrintListInReversedOrder.h"

#include <stack>
#include <stdio.h>

#include "../Structure.h"

void PrintListReversingly_Iteratively(ListNode* pHead)
{
    std::stack<ListNode*> nodes;

    ListNode* pNode = pHead;
    while (pNode != NULL)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    while (!nodes.empty())
    {
        pNode = nodes.top();
        printf("%d\t", pNode->m_nValue);
        nodes.pop();
    }
}

void PrintListReversingly_Recursively(ListNode* pHead)
{

}