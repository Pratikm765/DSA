#include<bits/stdc++.h>
using namespace std;

int RodCutting(int val[],int n,int len)
{
    int dp[n+1][len+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=len;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(i<=j)//instead of i len[i]can be created where len[i]=i+1
                dp[i][j]=max(val[i-1]+dp[i][j-i],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][len];

}

int main()
{       
    int val[]={1,3,5};//arr for cut 1,2,3
    cout<<RodCutting(val,3,8);//cut 2 3 3 =3+5+5=13
    return 0;
}