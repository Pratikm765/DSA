#include <bits/stdc++.h>

using namespace std;

int Log2(int n)
{
    int count = -1;
    while(n)
    {
        n = n >> 1;
        count++;
    }
    return count;
}

int main()
{
    cout << Log2(8);
    return 0;
}