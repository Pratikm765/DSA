#include <bits/stdc++.h>
using namespace std;

int LISTab(int arr[],int n)
{
    int dp[n];
    dp[0]=arr[0];

    for(int i=1;i<n;i++)
    {
        dp[i]=arr[i];
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i] && dp[i]<dp[j]+arr[i])
                dp[i]=dp[j]+arr[i];
        }
    }

    return *max_element(dp,dp+n);
}

int main()
{
    int arr[]={1,10,2,5};
    int arr1[]={2, 3, 5, 1, 4, 7, 6};
    cout<<LISTab(arr1,7);
    return 0;
}