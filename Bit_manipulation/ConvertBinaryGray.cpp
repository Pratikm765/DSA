#include <bits/stdc++.h>
using namespace std;

int ConverttoGray(int num)
{
    // 1111
    // 0 to i to n index
    // gi = bi ^ bi+1
    int result = 0;
    int temp = num;

    int mask = 1;

    while(temp)
    {
        result = result | ( (num & mask) ^ ((num >> 1) & mask));

        temp = temp >> 1;
        mask = mask << 1;
    }
    return result;
}

int ConverttoBinary(int num)
{
    // 1000
    // 0 to i to n
    // bi = gi ^ gi+1 ^ gi+2 ^ ... ^ gn

    int msb = 31 - __builtin_clz(num);
    int result = 0;
    int curr = 0;

    int mask = 1 << msb;

    while(mask)
    {
        curr = ((num & mask) ^ ((curr >> 1) & mask));
        result = result | curr;

        mask = mask >> 1;
    }
    return result;
}

int main()
{
    // int t = 0;
    // cin >> t;

    for(int t = 0; t <= 15; t++)
    {
        cout << t << " --> ";

        t = ConverttoGray(t);
        cout << t << " --> ";

        t = ConverttoBinary(t);
        cout << t << endl;
    }
    return 0;
}