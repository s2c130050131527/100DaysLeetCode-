// Runtime: 4 ms, faster than 93.56% of C++ online submissions for Binary Tree Level Order Traversal.
// Memory Usage: 12.6 MB, less than 100.00% of C++ online submissions for Binary Tree Level Order Traversal.

#include "iostream"
#include "vector"
#include "queue"

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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> a;
    if (root == NULL)
    {
        return a;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (q.size() > 0)
    {
        int size = q.size();
        vector<int> b;
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            b.push_back(temp->val);
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        a.push_back(b);
    }
    return a;
}
int main()
{
    TreeNode a(15);
    TreeNode b(7);
    TreeNode c(9);
    TreeNode d(2, &a, &b);
    TreeNode e(1, &c, &d);

    vector<vector<int>> res = levelOrder(&e);
    for (auto k : res)
    {
        for (auto m : k)
        {
            cout << m << '\t';
        }
        cout << endl;
    }
}