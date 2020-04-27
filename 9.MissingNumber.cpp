#include "iostream"
#include "vector"
using namespace std;

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int aS = (n * (n + 1)) / 2;
    int rS = 0;
    for (int k : nums)
    {
        rS += k;
    }
    return aS - rS;
}
int main()
{
    vector<int> a = {0, 1, 3};
    int res = missingNumber(a);
    cout << res << endl;
    return 0;
}
