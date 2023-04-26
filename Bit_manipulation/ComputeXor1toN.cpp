#include <bits/stdc++.h>

using namespace std;

int ComputeXor1toN(int n)
{
    switch(n%4)
    {
        case 0:
            return n;
        case 1:
            return 1;
        case 2:
            return n+1;
        case 3:
            return 0;
    }
    return 0;
}

int main()
{
    cout << ComputeXor1toN(8);
    return 0;
}