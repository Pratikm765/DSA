#include <bits/stdc++.h>

using namespace std;

int MSBSetBit(int n)
{
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);
    n = n | (n >> 16);

    n = n + 1;

    return log2(n >> 1)+1;
}

int main()
{
    // 100110
    cout << MSBSetBit(38);
    return 0;
}