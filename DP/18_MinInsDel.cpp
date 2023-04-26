#include<bits/stdc++.h>
using namespace std;

void MinimumInsertionDeletion(string x,string y,int m,int n)
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

    cout<<"LCS: "<<dp[m][n]<<endl;
    cout<<"Insertion Needed: "<<n-dp[m][n]<<endl;
    cout<<"Deletion Needed:  "<<m-dp[m][n]<<endl;
}

int main(){
    // string x="peak";
    // string y="heap";
    string x="AGGTAB";
    string y="GXTXAYB";
    //MinimumInsertionDeletion(x,y,4,4);
    MinimumInsertionDeletion(x,y,6,7);
    return 0;
}