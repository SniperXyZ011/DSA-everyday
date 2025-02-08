// Find length of Loop
// Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
class Solution {
    public:
      // Function to find the length of a loop in the linked list.
      int countNodesinLoop(Node *head) {
          // Code here
          Node* fast = head;
          Node* slow = head;
          bool isLoop = false;
          
          while(fast != NULL && fast-> next != NULL){
              slow = slow -> next;
              fast = fast -> next -> next;
              
              if(fast == slow){
                  isLoop = true;
                  break;
              }
          }
          
          if(!isLoop){
              return 0;
          }
          
          slow = head;
          while(slow != fast){
              slow = slow -> next;
              fast = fast -> next;
          }
          
          // now your fast and slow ptr is pointing to the joining node
          Node* temp = slow;
          int count = 1;
          temp = temp -> next;
          while(temp != slow){
              temp = temp -> next;
              count++;
          }
          
          return count;
      }
  };