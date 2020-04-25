
#include <iostream>
#include <vector>
using namespace std;

vector<int> prodcutExceptSelf(vector<int> &nums)
{
    int pro = 1;
    vector<int> leftArr;
    vector<int> res;
    int R = 1;
    for (int n : nums)
    {
        leftArr.push_back(pro);
        pro = pro * n;
    }
    pro = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        leftArr[i] = leftArr[i] * R;
        R *= nums[i];
    }
    return leftArr;
}

int main()
{
    vector<int> a = {3, 2, 1};
    vector<int> res = prodcutExceptSelf(a);
    for (int n : res)
    {
        cout << n << endl;
    }
    return 0;
}
