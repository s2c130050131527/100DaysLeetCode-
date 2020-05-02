/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Invert Binary Tree.
*/

#include "iostream"

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

TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
    {
        return root;
    }
    helper(root);
    return root;
}

void helper(TreeNode *root)
{
    if (root == NULL)
        return;
    helper(root->left);
    helper(root->right);
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    return;
}
