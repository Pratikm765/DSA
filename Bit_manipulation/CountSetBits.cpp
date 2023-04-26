#include <bits/stdc++.h>

using namespace std;

int CountSetBits(int n)
{
    int count = 0;
    while(n)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}

int main()
{
    cout << CountSetBits(10);
    return 0;
}