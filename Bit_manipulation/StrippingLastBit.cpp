#include <bits/stdc++.h>

using namespace std;

int strippingLastSetBit(int n)
{
    // 10010 & 10001 = 10000
    n = n & (n-1);
    return n;
}

int main()
{
    cout << strippingLastSetBit(18);
    return 0;
}