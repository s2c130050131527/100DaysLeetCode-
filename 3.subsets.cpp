
#include <iostream>
#include <vector>
#define VVI vector<vector<int>>
#define VI vector<int>

using namespace std;

void backtrack(VVI &list, VI temp, int start, VI nums)
{
    list.push_back(temp);
    for (int i = start; i < nums.size(); i++)
    {
        temp.push_back(nums[i]);
        backtrack(list, temp, i + 1, nums);
        temp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> list;
    if (nums.size() == 0)
    {
        return list;
    }
    vector<int> i;
    backtrack(list, i, 0, nums);
    return list;
}

int main()
{
    vector<int> a = {3, 2, 1};
    vector<vector<int>> res = subsets(a);
    for (auto n : res)
    {
        for (int j : n)
        {

            cout << j << endl;
        }
        cout << endl;
    }
    return 0;
}
