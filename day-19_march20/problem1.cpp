// 543. Diameter of Binary Tree
// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftHt = height(root->left);
        int rightHt = height(root->right);

        return max(leftHt, rightHt) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {

        if (root == NULL)
            return 0;

        int currDiam = height(root->left) + height(root->right);
        int leftDiam = diameterOfBinaryTree(root->left);
        int rightDiam = diameterOfBinaryTree(root->right);

        return max(currDiam, max(leftDiam, rightDiam));
    }
};