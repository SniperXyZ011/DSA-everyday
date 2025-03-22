// Bottom View of Binary Tree
// Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

// Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will be considered.

#include <bits/stdc++.h>
using namespace std;

struct Node {
public:
    int data;
    Node* left;
    Node* right;
};

class Solution {
    public:
      vector <int> bottomView(Node *root) {
          // Your Code Here
          vector<int>ans;
          
          queue<pair<Node*, int>> Q; //(node, HD)
          map<int, int> m; //(HD, node -> data)
          
          Q.push(make_pair(root, 0));
          
          while(!Q.empty()){
              pair<Node*, int> curr = Q.front();
              Q.pop();
              
              m[curr.second] = curr.first -> data;
              
              if(curr.first -> left != NULL) Q.push(make_pair(curr.first -> left, curr.second -1));
              if(curr.first -> right != NULL) Q.push(make_pair(curr.first -> right, curr.second +1));
          }
          
          for(auto it:m){
              ans.push_back(it.second);
          }
          
          return ans;
      }
  };