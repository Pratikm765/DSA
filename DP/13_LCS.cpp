#include <bits/stdc++.h>
using namespace std;

//Memoization
//start from top to down 
int LCSMemo(string x, string y, int xl, int yl,vector<vector<int>>& dp)
{
    if(xl==0 || yl==0)
        return 0;

    //start from end
    //if it is already calculated
    if(dp[xl-1][yl-1] ==-1)
    {
        //if not came across same path before 
        //if curr characters are equal then add 1 and check for xl-1 & yl-1
        if(x[xl-1]==y[yl-1])
        {
            dp[xl-1][yl-1]=1+LCSMemo(x,y,xl-1,yl-1,dp);
        }
        else//if not same get max  from previous subsequences
        {
            dp[xl-1][yl-1]=max(LCSMemo(x,y,xl,yl-1,dp),LCSMemo(x,y,xl-1,yl,dp));
        }
    }
    return dp[xl-1][yl-1];
}

//bottomUp approach
//begin from start tabulate till top
int LCSTab(string x, string y, int xl, int yl)
{
    vector<vector<int>> dp(xl+1, vector<int>(yl+1, -1));
    for(int i=0;i<=xl;i++)
    {
        for(int j=0;j<=yl;j++)
        {
            //if zero element put zero bcos nothing is common between 0 and n len string
            if(i==0 || j==0)
                dp[i][j]=0;
            //if equal characters then add 1 to previous path
            else if(x[i]==y[j])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            //if not then get max of previous subsequences
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    //return top path value
    return dp[xl][yl];
}

int LCS(string x, string y, int xl, int yl)
{
    if(xl==0 || yl==0)
        return 0;

    if(x[xl-1]==y[yl-1])
    {
        return 1+LCS(x,y,xl-1,yl-1);
    }
    else
    {
        return max(LCS(x,y,xl,yl-1),LCS(x,y,xl-1,yl));
    }
}

int main()
{
    string x="holiday",y="echold";
    int n= x.length(), m = y.length();   
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    cout<<LCSTab(x,y,7,6);
    cout<<LCSMemo(x,y,7,6,dp);
    return 0;
}