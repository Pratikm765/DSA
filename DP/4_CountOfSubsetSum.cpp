#include<bits/stdc++.h>

using namespace std;

int CountOfSubsetSum(int arr[], int n,int s){

    int dp[n+1][s+1];
    for(int i=0;i<=s;i++)
        dp[0][i]=0;
    for(int i=0;i<=n;i++)
        dp[i][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][s];
}

int main(){
    int arr[] = { 3, 3, 3, 3 };
    int n = sizeof(arr) / sizeof(int);
    int x = 6;
 
    cout << CountOfSubsetSum(arr,n,x);

    return 0;
}