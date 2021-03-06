/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
*/

#include "iostream"
#include "vector"
#include "stack"
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

vector<int> inorderTraversal(TreeNode *root)
{

    vector<int> list;
    stack<TreeNode> s;
    TreeNode *curr = root;
    while (s.size() != 0 || curr != NULL)
    {
        while (curr != NULL)
        {
            s.push(*curr);
            curr = curr->left;
        }
        if (s.size() > 0)
        {
            curr = &(s.top());
            s.pop();
            list.push_back(curr->val);
            curr = curr->right;
        }
    }
    return list;
}
