#include <bits/stdc++.h>

using namespace std;

int ClearFromMSB(int n, int pos)
{
    // 11010111 & 00001111 = 00010
    n = n & (1 << pos) - 1;
    return n;
}

int main()
{
    cout << ClearFromMSB(215,4);
    return 0;
}