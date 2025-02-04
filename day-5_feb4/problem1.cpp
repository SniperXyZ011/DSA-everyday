// Given an integer array arr of size n. Construct the doubly linked list from arr and return the head of it.

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
       
        int n = arr.size();
        Node* head = new Node(arr[0]);
        Node* curr = head;
        
        for(int i = 1; i < n; i++){
            Node* temp = new Node(arr[i]);
            curr -> next = temp;
            temp -> prev = curr;
            curr = temp;
        }
        
        
        return head;;
        // code here
    }
};