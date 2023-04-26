#include<bits/stdc++.h>
using namespace std;

int LCS(string x,string y,int m,int n)
{
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
    return dp[m][n];
}

int MinDelForLPS(string x,int m)
{
    string y=x;
    reverse(y.begin(),y.end());
    return m-LCS(x,y,m,m); // same for insertion & deletion.
}

int main()
{
    string x="afbcba";
    cout<<MinDelForLPS(x,6);
    return 0;
}