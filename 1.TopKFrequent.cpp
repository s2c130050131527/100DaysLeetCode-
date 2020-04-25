#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> m;
    vector<vector<int>> v(nums.size() + 1);
    for (int n : nums)
        ++m[n];
    for (auto k : m)
        v[k.second].push_back(k.first);

    vector<int> res;
    for (auto b = v.end(); b != v.begin(); b--)
    {

        for (auto n : *b)
        {
            res.push_back(n);
            if (res.size() == target)
                return res;
        }
    }
}

int main()
{
    vector<int> a = {1, 1, 1, 2, 2, 3};
    vector<int> res = twoSum(a, 2);
    for (int n : res)
    {
        cout << n << endl;
    }
    return 0;
}