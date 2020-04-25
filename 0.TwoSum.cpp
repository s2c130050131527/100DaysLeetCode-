#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++)
    {
        int num = target - nums[i];
        auto it = map.find(num);
        while (it != map.end())
        {
            res.push_back(it->second);
            res.push_back(i);
            return res;
        }
        map[nums[i]] = i;
    }
}

int main()
{
    vector<int> a = {2, 7, 11, 15};
    vector<int> res = twoSum(a, 9);
    for (int n : res)
    {
        cout << n << endl;
    }
    return 0;
}