#include<bits/stdc++.h>
using namespace std;

void printSCS(string x,string y,int m,int n)
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
    int index=m+n-dp[m][n];
    char str[index+1];
    str[index]='\0';

    int xlen=m;
    int ylen=n;

    while(xlen>0 && ylen>0)
    {
        if(x[xlen-1]==y[ylen-1])
        {
            str[--index]=x[xlen-1];
            xlen--;
            ylen--;
        }
        else
        {
            if(dp[xlen-1][ylen]>dp[xlen][ylen-1])
            {
                str[--index]=x[xlen-1];
                xlen--;
            }
            else
            {
                str[--index]=y[ylen-1];
                ylen--;
            }
        }
    }
    while(xlen>0)
    {
        str[--index]=x[xlen-1];
        xlen--;
    }
    while(ylen>0)
    {
        str[--index]=y[ylen-1];
        ylen--;
    }

    cout<<"SCS: "<<str<<endl;

}

int main(){
    string x="GXTXAYB";
    string y="AGGTAB";
    printSCS(x,y,7,6);
    return 0;
}