#include<bits/stdc++.h>
using namespace std;

bool SequencePatternMatching(string str,string pat,int m,int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(str[i-1]==pat[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    if(dp[m][n]==n)
        return true;
    else    
        return false;
}

int main()
{
    string str="abxcpy";
    string pat="axy";
    cout<<SequencePatternMatching(str,pat,6,3);
}