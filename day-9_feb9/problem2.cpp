// 328. Odd Even Linked List
// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

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

class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
            ListNode* odd = head;
            if(head == NULL || head -> next == NULL){
                return head;
            }
            ListNode* even = head -> next;
            ListNode* temp = head -> next;
    
            while(odd -> next != NULL && even -> next != NULL){
                odd -> next = even -> next;
                odd = odd -> next;
                even -> next = odd -> next;
                even = even -> next;
            }
    
            odd -> next = temp;
    
            return head;
        }
    };