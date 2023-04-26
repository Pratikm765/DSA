#include <bits/stdc++.h>
using namespace std;

int min(int x, int y, int z) { return min(min(x, y), z); }

int EditStrTab(string s1,string s2,int m,int n)
{
    int dp[m+1][n+1]={-1};
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
                dp[i][j]=j;//if str1 empty then maxop=str2.length
            else if(j==0)
                dp[i][j]=i;//if str2 empty then maxop=str1.length
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];//Matched So ignored
            else
                dp[i][j]=1+min(dp[i][j-1],//Insert
                                dp[i-1][j],//Delete
                                dp[i-1][j-1]//Replace
                                );

        }
    }
    return dp[m][n];
}


int EditStrMemo(string s1,string s2,int m,int n,vector<vector<int>>& dp)
{
    if(m==0)
        return n;
    if(n==0)
        return m;

    if(dp[m-1][n-1]==-1)
    {
        if(s1[m-1]==s2[n-1])
            dp[m-1][n-1]=EditStrMemo(s1,s2,m-1,n-1,dp);
        else
            dp[m-1][n-1]=1+min(EditStrMemo(s1,s2,m,n-1,dp),
                           EditStrMemo(s1,s2,m-1,n,dp),
                           EditStrMemo(s1,s2,m-1,n-1,dp)
                        );
    }
    return dp[m-1][n-1];
}

int main()
{
    string str1 = "sunday";
    string str2 = "saturday";
 
    int n= str1.length(), m = str2.length();   
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
        
    cout << EditStrTab(str1,str2,str1.length(),str2.length())<<endl;
    cout << EditStrMemo(str1,str2,str1.length(),str2.length(),dp)<<endl;
    return 0;
}