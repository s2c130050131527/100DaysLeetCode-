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

vector<int> rightSideView(TreeNode *root)
{
    vector<int> r;
    if (root == NULL)
        return r;
    TreeNode *curr = root;
    r.push_back(curr->val);
    while (curr->left != NULL || curr->right != NULL)
    {
        if (curr->right != NULL)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
        r.push_back(curr->val);
    }
    return r;
}

int main()
{
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(2, nullptr, &a);
    TreeNode d(3, nullptr, &b);

    TreeNode e(1, &c, &d);
    // TreeNode f(13);
    // TreeNode g(4, &c, &d);

    // TreeNode h(4, &e, nullptr);
    // TreeNode i(8, &f, &g);
    // TreeNode j(5, &h, &i);
    vector<int> res = rightSideView(&e);
    for (auto k : res)
    {
        cout << k << endl;
    }
}