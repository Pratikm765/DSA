#include <bits/stdc++.h>

using namespace std;

int unsetBit(int n, int pos)
{
    // 11010 & 01000 = 10010
    n = n & ~ (1 << pos-1);
    return n;
}

int main()
{
    cout << unsetBit(26,4);
    return 0;
}