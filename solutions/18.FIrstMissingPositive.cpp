/*
Runtime: 4 ms, faster than 50.24% of C++ online submissions for First Missing Positive.
Memory Usage: 9.9 MB, less than 6.00% of C++ online submissions for First Missing Positive.
*/

#include "iostream"
#include "vector"
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0 || nums[i] > n)
        {
            nums[i] = n + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int num = abs(nums[i]);
        if (num > n)
        {
            continue;
        }
        num--;
        if (nums[num] > 0)
        {
            nums[num] *= -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= 0)
            return i + 1;
    }
    return n + 1;
}

int main()
{
    vector<int> a = {3, 2, 0};
    int res = firstMissingPositive(a);
    cout << res << endl;
}