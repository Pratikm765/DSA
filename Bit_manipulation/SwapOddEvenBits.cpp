#include <bits/stdc++.h>

using namespace std;

int SwapOddEvenBits(int m)
{
    for(int i = 0; i < 32; i+=2)
    {
        int ith_bit = (m >> i) & 1;
        int iplus1_bit = (m >> (i+1)) & 1;

        m = m - (ith_bit << i)
            - (iplus1_bit << (i+1))
            + (iplus1_bit << i)
            + (ith_bit << (i+1));
    }
    return m;
}

int main()
{
    cout << SwapOddEvenBits(23);
    return 0;
}