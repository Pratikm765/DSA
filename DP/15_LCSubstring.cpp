#include<bits/stdc++.h>
using namespace std;

// x = abcdxyz
// y = xyzabcd
//      0   x   y   z   a   b   c   d
//  0   0   0   0   0   0   0   0   0
//  a   0   0   0   0   1   0   0   0
//  b   0   0   0   0   0   2   0   0
//  c   0   0   0   0   0   0   3   0
//  d   0   0   0   0   0   0   0   4
//  x   0   1   0   0   0   0   0   0 
//  y   0   0   2   0   0   0   0   0
//  z   0   0   0   3   0   0   0   0

int LCSubstring(string x,string y,int m,int n)
{
    int dp[m+1][n+1];
    int maxlen=INT_MIN;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(x[i-1]==y[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=0;
            
            maxlen=max(maxlen,dp[i][j]);
        }
    }
    return maxlen;
}

int main(){

    string x="abcdfhm";
    string y="bcdabcdf";
    cout<<LCSubstring(x,y,7,8);
    return 0;
}