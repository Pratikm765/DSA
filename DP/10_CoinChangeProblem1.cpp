#include<bits/stdc++.h>
using namespace std;
int NoOfWaysToChange(int coins[],int n,int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<=sum;i++)
        dp[0][i]=0;
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(coins[i-1]<=j)
                dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main(){

    int coins[]={1,2,5};
    cout<<NoOfWaysToChange(coins,3,8);
    //for 5= 4{11111,1112,122,5}
    //for 8= 7{11111111,1111112,111122,11222,2222,1115,125}
    return 0;
}