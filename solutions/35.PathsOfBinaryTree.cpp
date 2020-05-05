// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Paths.
// Memory Usage: 13.4 MB, less than 5.26% of C++ online submissions for Binary Tree Paths.

#include "iostream"
#include "vector"

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

void helper(TreeNode *root, string path, vector<string> &list)
{
    if (root->left == NULL && root->right == NULL)
    {
        list.push_back(path + to_string(root->val));
    }
    if (root->left != NULL)
    {
        helper(root->left, path + to_string(root->val) + "->", list);
    }
    if (root->right != NULL)
    {
        helper(root->right, path + to_string(root->val) + "->", list);
    }
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> res;
    if (root == NULL)
    {
        return res;
    }
    helper(root, "", res);
    return res;
}

int main()
{
    TreeNode a(7);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(1);

    TreeNode e(11, &a, &b);
    TreeNode f(13);
    TreeNode g(4, &c, &d);

    TreeNode h(4, &e, nullptr);
    TreeNode i(8, &f, &g);
    TreeNode j(5, &h, &i);
    vector<string> res = binaryTreePaths(&j);
    for (auto k : res)
    {

        cout << k << endl;
    }
}