#include "iostream"
using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t res = 0;
    for (int i = 0; i < 32; i++)
    {
        int end = n & 1;
        n = n >> 1;
        res = res << 1;
        res |= end;
    }
    return res;
}

int main()
{
    uint32_t n = 43261596;
    uint32_t l = reverseBits(n);
    cout << l << endl;
    return 0;
}
