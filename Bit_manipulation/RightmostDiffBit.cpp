#include <bits/stdc++.h>

using namespace std;

int RightmostDiffBit(int m, int n)
{
    // 1011 ^ 0101 = 1110
    int p = m^n;

    if(p == 0)
        return 0;
        
    return log2(p & -p) + 1;
}

int main()
{
    cout << RightmostDiffBit(11,9);
    return 0;
}