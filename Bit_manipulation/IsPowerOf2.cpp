#include <bits/stdc++.h>

using namespace std;

bool IsPowerOf2(int n)
{
    // 10010 & 10001 = 10000
    return n && !(n & (n-1));
}

int main()
{
    cout << IsPowerOf2(64);
    return 0;
}