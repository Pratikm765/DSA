#include<bits/stdc++.h>
using namespace std;

// x = acbcf
// y = abcdaf
//      0   a   b   c   d   a   f
//  0   0   0   0   0   0   0   0
//  a   0   1   1   1   1   1   1
//  c   0   1   1   2   2   2   2
//  b   0   1   2   2   2   2   2
//  c   0   1   2   3   3   3   3
//  f   0   1   2   3   3   3   4

void PrintLCS(string x,string y,int xlen,int ylen)
{
    int dp[xlen+1][ylen+1];
    for(int i=0;i<=xlen;i++)
    {
        for(int j=0;j<=ylen;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(x[i-1]==y[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    int index=dp[xlen][ylen];
    char str[index+1];
    str[index]='\0';
    int m=xlen,n=ylen;

    while(m>0 && n>0)
    {
        if(x[m-1]==y[n-1])
        {
            str[--index]=x[m-1];
            m--;
            n--;
        }
        else
        {
            if(dp[m-1][n]>dp[m][n-1])
                m--;
            else
                n--;
        }
    }
    cout<<str<<endl;
}

int main(){
    string x="AGGTAB";
    string y="GXTXAYB";
    PrintLCS(x,y,6,7);
    return 0;
}