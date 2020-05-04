#include "iostream"
#include "vector"
using namespace std;
void moveZeroes(vector<int> &nums)
{
    int in = 0;
    int temp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            temp = nums[in];
            nums[in] = nums[i];
            nums[i] = temp;
            in++;
        }
    }
}

int main()
{
    vector<int> a = {0, 1, 0, 3, 12};
    moveZeroes(a);
    for (auto k : a)
    {
        cout << k << endl;
    }
}