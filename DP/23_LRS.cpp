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
            else if(x[i-1]==y[j-1] && i!=j)//Little Modification to get repeated Sub
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int LongestRepeatingSubsequence(string x,int m){
    return LCS(x,x,m,m);
}

int main(){
    string x="aabebcdd";
    cout<<LongestRepeatingSubsequence(x,8);//abd
    return 0;
}