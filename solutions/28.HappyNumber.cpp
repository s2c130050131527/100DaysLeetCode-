#include "iostream"

using namespace std;

int findSquare(int n)
{
    int square = 0;
    while (n > 0)
    {
        int m = n % 10;
        square += m * m;
        n /= 10;
    }
    return square;
}
bool isHappy(int n)
{
    int slow = n, fast = n;
    do
    {
        slow = findSquare(slow);
        fast = findSquare(findSquare(fast));
    } while (slow != fast);
    return slow == 1;
}

int main()
{
    int n = 211;
    bool res = isHappy(n);
    cout << res << endl;
    return 0;
}