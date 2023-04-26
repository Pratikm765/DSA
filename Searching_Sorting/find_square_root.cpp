#include<bits/stdc++.h>

using namespace std;

// Square root using binary search
float findSquareRoot(int n, int p)
{
    float result = 0;
    int l = 0, h = n;
    while(l <= h)
    {
        int mid = l+(h-l)/2;

        if(mid*mid == n)
        {
            result = mid;
            break;
        }
        
        if(mid*mid < n)
        {
            result = mid;
            l = mid+1;
        }
        else
        {
            h = mid-1;
        }
    }

    float mul = 0.1;
    for(int i = 0; i < p; i++)
    {
        while(result*result <= n)
        {
            result+= mul;
        }
        result-= mul;
        mul*=0.1;
    }
    return result;
}

int main()
{
    int a;
    cin >> a;
    cout << findSquareRoot(a,4);
    return 0;
}