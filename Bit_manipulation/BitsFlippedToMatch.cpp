#include <bits/stdc++.h>

using namespace std;

int BitsFlippedToMatch(int m, int n)
{
    // 01010 ^ 10100 = 11110 (4)
    // 0111 ^ 1010 = 1101 (3)
    int p = m^n;
    int count = 0;

    while(p)
    {
        p = p & (p-1);
        count++;
    }
    return count;
}

int main()
{
    cout << BitsFlippedToMatch(7,10);
    return 0;
}