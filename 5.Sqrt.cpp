#include "iostream"
using namespace std;

int mySqrt(int x)
{
    long int left = 1, right = x;
    long int sqr;
    if (x < 2)
    {
        return x;
    }
    while (left < right)
    {
        long int mid = left + ((right - left) / 2);
        sqr = mid * mid;
        if (sqr == x)
            return mid;
        else if (sqr > x)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left - 1;
}

int main()
{
    int sq = 1073697800;
    int res = mySqrt(sq);
    cout << res << endl;
    return 0;
}
