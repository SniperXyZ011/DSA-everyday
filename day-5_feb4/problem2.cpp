// Doubly linked list Insertion at given position
// Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the position just after pth node in the doubly linked list and return the head of the updated list.

#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        Node* temp = head;

        int count = 0;
        while(count < pos && temp -> next != NULL){
            temp = temp -> next;
            count++;
        }
        
        Node* node = new Node(data);
        
        if(temp -> next == NULL){
            temp -> next = node;
            node -> prev = temp;
        }else {
            node -> next = temp -> next;
            node -> prev = temp;
            temp -> next -> prev = node;
            temp -> next = node;
        }
        
        return head;
        
    }
};