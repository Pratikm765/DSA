#include <bits/stdc++.h>
using namespace std;

int UnboundedKnapsack(int val[],int w[],int n,int W)
{
    int dp[n+1][W+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(w[i-1]<=j)
                dp[i][j]=max(val[i-1]+dp[i][j-w[i-1]],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][W];
}

int UnboundedKnapsackMemo(int val[],int w[],int n,int W,vector<vector<int>>& dp)
{
    if(n==0 || W==0)
        return 0;
    
    if(dp[n][W]!=-1)
        return dp[n][W];

    if(w[n-1]<=W)
        return dp[n][W]=max(val[n-1]+UnboundedKnapsackMemo(val,w,n,W-w[n-1],dp),
                    UnboundedKnapsackMemo(val,w,n-1,W,dp));
    else
        return dp[n][W]=UnboundedKnapsackMemo(val,w,n-1,W,dp);
}

int main(){

    int val[]={1,4,5,8};
    int w[]={1,3,4,7};
    cout<<UnboundedKnapsack(val,w,4,7);

    vector<vector<int>> dp(5,vector<int>(8,-1));
    cout<<UnboundedKnapsackMemo(val,w,4,7,dp);
    return 0;
}