// Error in Submission

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

vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    vector<vector<int>> a;
    if (root == NULL)
        return a;

    queue<TreeNode *> q;
    q.push(root);
    while (q.size() > 0)
    {
        int n = q.size();
        vector<int> level;
        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            level.push_back(temp->val);
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        a.insert(a.begin(), level);
    }
    return a;
}

int main()
{
    TreeNode a(15);
    TreeNode b(7);
    TreeNode c(20, &a, &b);
    TreeNode d(9);
    TreeNode e(3, &d, &c);
    vector<vector<int>> res = levelOrderBottom(&e);
    for (auto k : res)
    {
        for (auto c : k)
        {
            cout << c << "\t";
        }
        cout << endl;
    }
}