// Runtime: 4 ms, faster than 98.97% of C++ online submissions for Path Sum II.
// Memory Usage: 19.9 MB, less than 84.21% of C++ online submissions for Path Sum II.

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

void helper(TreeNode *root, vector<int> &list, vector<vector<int>> &res, int sum)
{
    if (root == NULL)
    {
        return;
    }
    list.push_back(root->val);
    if (root->left == NULL && root->right == NULL && root->val == sum)
    {
        res.push_back(list);
    }
    else
    {
        helper(root->left, list, res, sum - root->val);
        helper(root->right, list, res, sum - root->val);
    }
    list.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int sum)
{
    vector<vector<int>> res;
    vector<int> list;
    helper(root, list, res, sum);
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
    vector<vector<int>> res = pathSum(&j, 22);
    for (auto k : res)
    {
        for (auto m : k)
        {

            cout << m << "\t";
        }
        cout << endl;
    }
}