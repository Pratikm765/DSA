#include <bits/stdc++.h>

using namespace std;

int toggleBit(int n, int pos)
{
    // 11010 ^ 01000 = 10010
    n = n ^ (1 << pos-1);
    return n;
}

int main()
{
    cout << toggleBit(18,4);
    return 0;
}