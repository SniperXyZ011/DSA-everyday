// 160. Intersection of Two Linked Lists
// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while (tempA != tempB)
        {
            tempA = tempA == NULL ? headB : tempA->next;
            tempB = tempB == NULL ? headA : tempB->next;
        }

        return tempA;
    }
};