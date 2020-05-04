// Runtime: 8 ms, faster than 48.39% of C++ online submissions for Maximum Subarray.
// Memory Usage: 13.3 MB, less than 5.88% of C++ online submissions for Maximum Subarray.

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
int maxSubArray(vector<int> &nums)
{
    int prev = nums[0];
    int current = 0;
    int maximum = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (prev <= 0)
        {
            current = nums[i];
        }
        else
        {
            if (prev + nums[i] < 0)
            {
                current = nums[i];
            }
            else
            {
                current = prev + nums[i];
            }
        }
        maximum = max(current, maximum);
        prev = current;
    }
    return maximum;
}

int main()
{
    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int res = maxSubArray(a);
    cout << res << endl;
    return 0;
}