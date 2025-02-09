// 19. Remove Nth Node From End of List
// Given the head of a linked list, remove the nth node from the end of the list and return its head.

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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* temp = head;
            int count = 1;
            while(temp -> next != NULL){
                temp = temp -> next;
                count++; //No of nodes in the ll
            }
    
            int idx = count - n; //idx of node whose next should be removed;
            count = 1;
            temp = head;
    
            if(idx == 0){
                head = head -> next;
                delete temp;
                return head;
            }
    
            ListNode* prev = NULL;
            while(count <= idx){
                prev = temp;
                temp = temp -> next;
                count++;
            }
    
            prev -> next = temp -> next;
            delete temp;
    
            return head;
        }
    };