#include<bits/stdc++.h>

using namespace std;

bool SubsetSum(int arr[], int n,int s){

    bool dp[n+1][s+1];
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

    return dp[n][s];
}

int main(){
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int sum2= 30;
    int n = sizeof(set) / sizeof(set[0]);

    if (SubsetSum(set, n, sum) == true)
        cout<<"Found a subset with given sum\n";
    else
        cout<<"No subset with given sum\n";

    if (SubsetSum(set, n, sum2) == true)
        cout<<"Found a subset with given sum\n";
    else
        cout<<"No subset with given sum\n";

    return 0;
}