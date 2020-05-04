// Runtime: 16 ms, faster than 76.17% of C++ online submissions for Find Largest Value in Each Tree Row.
// Memory Usage: 22.2 MB, less than 10.53% of C++ online submissions for Find Largest Value in Each Tree Row.

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

vector<int> largestValues(TreeNode *root)
{
    vector<int> a;
    if (root == NULL)
        return a;

    queue<TreeNode *> q;
    q.push(root);
    while (q.size() > 0)
    {
        int n = q.size();
        int max = INT32_MIN;
        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (max < temp->val)
            {
                max = temp->val;
            }
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        a.push_back(max);
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
    vector<int> res = largestValues(&e);
    for (auto k : res)
    {
        cout << k << endl;
    }
}