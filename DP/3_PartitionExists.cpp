#include<bits/stdc++.h>

using namespace std;

int SubsetSum(int arr[], int n,int s){

    bool dp[n+1][s+1];
    for(int i=0;i<=s;i++)
        dp[0][i]=false;
    for(int i=0;i<=n;i++)
        dp[i][0]=true;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][s];
}

bool PartitionExists(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];

    if(sum%2)
        return false;
    else
        return SubsetSum(arr,n,sum/2);
}

int main(){
    int arr[] = { 3, 1, 5, 9, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);

    if (PartitionExists(arr, n))
        cout << "Can be divided into two subsets "
                "of equal sum\n";
    else
        cout << "Can not be divided into two subsets"
                " of equal sum\n";

    int arr1[] = {1,5,3};
    n = sizeof(arr1) / sizeof(arr1[0]);

    if (PartitionExists(arr1, n))
        cout << "Can be divided into two subsets "
                "of equal sum\n";
    else
        cout << "Can not be divided into two subsets"
                " of equal sum\n";

    return 0;
}