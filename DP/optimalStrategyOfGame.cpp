#include <bits\stdc++.h>
using namespace std;

int optimalStrategyOfGame(int arr[],int n)
{
    int dp[n][n];

    //start from diagonal elements
    //then move upwards into upper half
    for(int k=0;k<n;k++)
    {
        for(int i=0,j=k;j<n;++i,++j)
        {
            int x=((i+2)<=j)?dp[i+2][j]:0;
            //user selected i and opponent selected i+1

            int y=((i+1)<=(j-1))?dp[i+1][j-1]:0;
            //user selected i and opponent selected j
            //user selected j and opponent selected i

            int z=((i)<=(j-2))?dp[i][j-2]:0;
            //user selected j and opponent selected j-1

            dp[i][j]=max(
                arr[i]+min(x,y),//opponent leaves min of x&y
                arr[j]+min(y,z)//opponent leaves min of y&z
            );
        }
    }
    return dp[0][n-1];
}

int main()
{
    int arr1[] = { 8, 15, 3, 7 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    cout<<optimalStrategyOfGame(arr1, n);
    return 0;
}