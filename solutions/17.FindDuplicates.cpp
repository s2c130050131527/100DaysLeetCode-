/*
Runtime: 124 ms, faster than 34.50% of C++ online submissions for Find All Duplicates in an Array.
Memory Usage: 33.6 MB, less than 5.00% of C++ online submissions for Find All Duplicates in an Array.
*/

#include "iostream"
#include "vector"
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> res;
    if (nums.size() == 0)
        return res;
    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0)
            res.push_back(index + 1);
        else
            nums[index] = -nums[index];
    }
    return res;
}

int main()
{
    vector<int> a = {};
    vector<int> res = findDuplicates(a);
    for (auto b : res)
    {
        cout << b << endl;
    }
}