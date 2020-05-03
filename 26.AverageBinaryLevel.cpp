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

vector<double> averageOfLevels(TreeNode *root)
{
    vector<double> a;
    queue<TreeNode *> q;
    q.push(root);
    while (q.size() > 0)
    {
        int n = q.size();
        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            sum += temp->val;
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        a.push_back(sum / n);
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
    vector<double> res = averageOfLevels(&e);
    for (auto k : res)
    {
        cout << k << endl;
    }
}