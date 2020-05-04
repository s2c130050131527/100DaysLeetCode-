/*
Runtime: 8 ms, faster than 99.60% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.
Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.
*/

#include "iostream"
#include "vector"
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    vector<int> c(101, 0);
    for (auto d : nums)
    {
        c[d]++;
    }
    for (int m = 1; m <= 100; m++)
    {
        c[m] = c[m] + c[m - 1];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
            nums[i] = c[nums[i] - 1];
    }
    return nums;
}

int main()
{
    vector<int> a = {5, 0, 10, 0, 10, 6};
    vector<int> res = smallerNumbersThanCurrent(a);
    for (auto b : res)
    {
        cout << b << endl;
    }
}