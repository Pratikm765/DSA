#include <bits/stdc++.h>

using namespace std;

int EqualAddXORPairs(int n)
{
    // i = 1 to n
    // n + i = (n ^ i) + 2 * (n & i)
    // n + i = (n ^ i) if  (n & i) = 0
    // To find such pairs count the unset bits in n 
    // permutations of that count i.e 2 raised to count
    // i.e. for n = 1010 different combinations = 1010 1011 1110 1111
    // i.e. for n = 100 different combinations = 100 101 110 111
    int count = 0;
    while(n)
    {
        if((n & 1) == 0)
            count++;
        n = n >> 1;
    }
    return 1 << count;
}

int main()
{
    cout << EqualAddXORPairs(12);
    return 0;
}