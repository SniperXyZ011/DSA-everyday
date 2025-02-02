// 206. Reverse Linked List
// Given the head of a singly linked list, reverse the list, and return the reversed list.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* nex = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nex;
        }

        return prev;
    }
};
