#include<bits/stdc++.h>

using namespace std;

int SubsetSum(int arr[], int n,int s){

    int dp[n+1][s+1];
    for(int i=0;i<=s;i++)
        dp[0][i]=0;
    for(int i=0;i<=n;i++)
        dp[i][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][s];
}
int CountOfSubsetSumDiff(int arr[],int n,int diff)
{
    int sum=0;
    for (int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return SubsetSum(arr,n,(sum+diff)/2);
}

int main(){
    //int arr[] = {3, 1, 4, 2, 2, 1};
    int arr[] = {3,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Total count of given difference between two sets is "
         << CountOfSubsetSumDiff(arr, n, 1);
    cout<<endl;
    cout << "Total count of given difference between two sets is "
         << CountOfSubsetSumDiff(arr, n, 3);

    return 0;
}