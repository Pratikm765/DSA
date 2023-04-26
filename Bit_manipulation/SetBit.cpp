#include <bits/stdc++.h>

using namespace std;

int setBit(int n, int pos)
{
    // 10010 | 01000 = 11010
    n = n | (1 << pos-1);
    return n;
}

int main()
{
    cout << setBit(18,4);
    return 0;
}