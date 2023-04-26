#include<bits/stdc++.h>

using namespace std;

int SubsetSum(vector<int>& arr, int n,int s){

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
int CountOfTargetSum(int arr[],int n,int target)
{
    target=abs(target);
    int sum=0;
    int zeros=0;
    vector<int> nums;
    for (int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(arr[i]==0)
            zeros++;// To handle multiple zeros in arr
        else
            nums.push_back(arr[i]);
    }
    // sub_sum + other_sum = sum
    // sub_sum - other_sum = target
    // sub_sum = (sum+target)/2
    // if target is greater than total sum then that will not exist
    // sum+target should be even 
    // for below testcase of sum 9 and target 1 exists with 4 and 5
    // but if you find for 9 and 2 subsets sum should be 5.5 and 3.5
    // which is not possible
    if(sum<target||(sum+target)%2!=0)
        return 0;

    // for 0,0,1 target= 1
    // -0-0+1 , -0+0+1 , +0-0+1, +0+0+1 that's why pow(2,2)*SubsetSum({1},1)
    return pow(2,zeros)*SubsetSum(nums,nums.size(),(sum+target)/2);
}

int main(){
    //int arr[] = {3, 1, 4, 2, 2, 1};
    int arr[] = {3,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Total count of given difference between two sets is "
         << CountOfTargetSum(arr, n, 1);
    cout<<endl;
    cout << "Total count of given difference between two sets is "
         << CountOfTargetSum(arr, n, 3);

    return 0;
}