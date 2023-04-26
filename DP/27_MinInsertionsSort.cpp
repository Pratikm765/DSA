#include <bits/stdc++.h>
using namespace std;

int LISTab(int arr[],int n)
{
    int dp[n];
    dp[0]=1;

    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i] && dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
        }
    }

    return n-*max_element(dp,dp+n);
}

int main()
{
    int arr[]={1,10,2,5};
    int arr1[]={2, 3, 5, 1, 4, 7, 6};
    cout<<LISTab(arr1,7);
    return 0;
}