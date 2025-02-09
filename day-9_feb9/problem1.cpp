// 234. Palindrome Linked List
// Given the head of a singly linked list, return true if it is a
// palindrome
//  or false otherwise.

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
        bool isPalindrome(ListNode* head) {
            ListNode* revhead = NULL;
            ListNode* curr = head;
            vector<int>temp;
            ListNode* tempvec = head;
    
            while(tempvec != NULL){
                temp.push_back(tempvec -> val);
                tempvec = tempvec -> next;
            }
    
            while(curr != NULL){
                ListNode* next = curr -> next;
                curr -> next = revhead;
                revhead = curr;
                curr = next;
            }
    
            int i = 0;
            while(revhead != NULL){
                if(revhead -> val == temp[i++]){
                    revhead = revhead -> next;
                    continue;
                }else {
                    return false;
                }
            }
    
    
            return true;
    
        }
    };