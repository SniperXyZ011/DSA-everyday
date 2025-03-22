// Top View of Binary Tree
// You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

// Note: 

// Return the nodes from the leftmost node to the rightmost node.
// If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. 

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
    public:
      // Function to return a list of nodes visible from the top view
      // from left to right in Binary Tree.
      vector<int> topView(Node *root) {
          // code here
          vector<int>ans;
          queue<pair<Node*, int>> Q; //(node, HD)
          map<int, int> m; //(HD, node -> data)
          
          Q.push(make_pair(root, 0));
          
          while(!Q.empty()){
              pair<Node*, int> curr = Q.front();
              Q.pop();
              
              if(m.count(curr.second) == 0){
                  m[curr.second] = curr.first -> data;
              }
              
              if(curr.first -> left != NULL) Q.push(make_pair(curr.first -> left, curr.second -1));
              if(curr.first -> right != NULL) Q.push(make_pair(curr.first -> right, curr.second +1));
          }
          
          for(auto it : m){
              ans.push_back(it.second);
          }
          
          return ans;
          
      }
  };