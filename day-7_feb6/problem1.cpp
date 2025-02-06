// 876. Middle of the Linked List
// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        int count = 0;
        ListNode *temp = head;

        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }

        int idx = count / 2;
        int count2 = 0;
        ListNode *temp2 = head;

        while (idx != count2)
        {
            temp2 = temp2->next;
            count2++;
        }

        return temp2;
    }
};