#include <bits/stdc++.h>

using namespace std;

bool checkBit(int n, int pos)
{
    // 11010 & 01000 = 01000 (true)
    bool st  = n & (1 << pos-1);
    return st;
}

int main()
{
    cout << checkBit(26,4);
    return 0;
}