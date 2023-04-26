#include <bits/stdc++.h>

using namespace std;

int ClearFromLSB(int n, int pos)
{
    // 10110 & 11100 = 10100
    n = n & ~((1 << pos+1) - 1);
    return n;
}

int main()
{
    cout << ClearFromLSB(26,1);
    return 0;
}