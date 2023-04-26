#include <bits/stdc++.h>

using namespace std;

int LowestSetBit(int n)
{
    n = n & (-n);
    return log2(n)+1;
}

int main()
{
    cout << LowestSetBit(18);
    return 0;
}