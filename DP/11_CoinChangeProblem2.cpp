#include<bits/stdc++.h>
using namespace std;

int MinCoinsForChange(int coins[],int n,int sum)
{
    int dp[n+1][sum+1];

    for(int i=0;i<=sum;i++)
        dp[0][i]=INT_MAX-1;
    for(int i=0;i<=n;i++)
        dp[i][0]=0;


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(coins[i-1]<=j)
                dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int coins[]={1,2,5};
    cout<<MinCoinsForChange(coins,3,5)<<endl;
    return 0;
}
