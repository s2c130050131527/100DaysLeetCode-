#include "iostream"
#include "sstream"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode *root)
{
    int h = 0;
    if (root == NULL)
        return 0;
    int leftSubHeightTree = maxDepth(root->left);
    int rightSubHeightTree = maxDepth(root->right);

    if (leftSubHeightTree > rightSubHeightTree)
    {
        h = leftSubHeightTree + 1;
    }
    else
    {
        h = 1 + rightSubHeightTree;
    }
}

int main()
{
    TreeNode t(5);

    int res = maxDepth(&t);
    cout << res << endl;
    return 0;
}
