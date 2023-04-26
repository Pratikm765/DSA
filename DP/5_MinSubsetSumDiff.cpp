#include<bits/stdc++.h>

using namespace std;

void SubsetSum(int arr[], int n,int s,vector<vector<bool>>& dp){

    for(int i=0;i<=s;i++)
        dp[0][i]=false;
    for(int i=0;i<=n;i++)
        dp[i][0]=true;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
}
int MinSubsetSumDiff(int arr[],int n)
{
    int sum=0;
    for (int i=0;i<n;i++)
    {
        sum+=arr[i];
    }

    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));

    SubsetSum(arr,n,sum,dp);

    int mn=INT_MAX;
    for(int i=0;i<=sum/2;i++)
    {
        if(dp[n][i])
            mn=min(mn,sum-2*i);
    }
    return mn;
}

int main(){
    //int arr[] = {3, 1, 4, 2, 2, 1};
    int arr[] = {1, 6, 11, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The minimum difference between two sets is "
         << MinSubsetSumDiff(arr, n);

    return 0;
}