#include<bits/stdc++.h>
using namespace std;

int getMax(int a,int b,int c)
{
    return max(a,max(b,c));
}
int maxCuts(int n,int a,int b,int c)
{
    if(n==0)
        return 0;
    if(n<0)
        return -1;

    int i=maxCuts(n-a,a,b,c);
    int j=maxCuts(n-b,a,b,c);
    int k=maxCuts(n-c,a,b,c);

    return getMax(i>-1?i+1:-1,
                  j>-1?j+1:-1,
                  k>-1?k+1:-1);
}

// 7 2 3 4
//  -1 -1 -1 -1 -1 -1 -1 -1
//   0 -1 -1 -1 -1 -1 -1 -1
// 0 0 -1  1  1  1 -1 -1 -1
// 1 0 -1  1  1  1 -1 -1 -1
// 2 0 -1  1  1  2  2  2 -1
// 3 0 -1  1  1  2  2  2  2
// 4 0 -1  1  1  2  2  3  3
// 5 0 -1  1  1  2  2  3  3
// 6 0 -1  1  1  2  2  3  3
// 7 0 -1  1  1  2  2  3  3
int maxCutsDP(int n,int a,int b,int c)
{
    int dp[n+1]={-1};
    dp[0]=0;

    for(int i=0;i<=n;i++)
    {
        if(dp[i]!=-1)
        {
            if(i+a<=n)
                dp[i+a]=max(dp[i]+1,dp[i+a]);
            if(i+b<=n)
                dp[i+b]=max(dp[i]+1,dp[i+b]);
            if(i+c<=n)
                dp[i+c]=max(dp[i]+1,dp[i+c]);
        }
    }
    return dp[n];
}

int main(){

    cout<<maxCutsDP(5,2,3,4);
    return 0;
}