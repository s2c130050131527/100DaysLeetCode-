#include "iostream"
#include "vector"
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        b[(i + k) % n] = nums[i];
    }
    nums = b;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    rotate(a, 3);
    for (int n : a)
    {
        cout << n << endl;
    }
    return 0;
}
