// 142. Linked List Cycle II
//     Given the head of a linked list,
//     return the node where the cycle begins.If there is no cycle, return null.

//     There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.Internally,
//     pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* ans;
        bool isCycle = false;

        //detecting the cycle
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;

            if(fast == slow){
                isCycle = true;
                break;
            }
        }

        //return null if no cycle
        if(!isCycle){
            return NULL;
        }

        // point the slow to head
        slow = head;
        if(slow == fast){       // if slow is already equal to fast return slow/head/fast
            return head;
        }else {
            while(slow != fast){       // check when slow is equal to fast and increment slow and fast by next
                slow = slow -> next;
                fast = fast -> next;
            }
        }

        return slow;
    }
};