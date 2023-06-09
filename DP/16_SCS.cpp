#include<bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(string x,string y,int m,int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(x[i-1]==y[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return m+n-dp[m][n];
}
int main(){

    string x="AGGTAB";
    string y="GXTXAYB";
    cout<<shortestCommonSupersequence(x,y,6,7);
    return 0;
}