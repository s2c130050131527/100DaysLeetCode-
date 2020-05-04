#include "iostream"
#include "vector"
#define VI vector<int>

using namespace std;

vector<int> sortedSquares(vector<int> &A)
{
    int i = 0;
    int j = A.size() - 1;
    VI res(j + 1);
    for (int k = j; k >= 0; k--)
    {
        if (abs(A[i]) > abs(A[j]))
        {
            res[k] = A[i] * A[i];
            i++;
        }
        else
        {
            res[k] = A[j] * A[j];
            j--;
        }
    }
    return res;
}
int main()
{
    VI a = {-7, -3, 2, 3, 11};
    VI res = sortedSquares(a);
    for (int n : res)
    {
        cout << n << endl;
    }
    return 0;
}
