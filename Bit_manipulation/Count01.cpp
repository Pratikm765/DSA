#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x = 30;
    bitset<32> t(x);
    cout << t << endl;
    cout << __builtin_clz(x) << endl;
    cout << __builtin_ctz(x) << endl;
    cout << __builtin_popcount(x) << endl;
    return 0;
}