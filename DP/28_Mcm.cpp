#include<bits/stdc++.h>
using namespace std;

int mcmRecur(vector<int>& dim, int i, int j){
    if(i==j)
        return 0;

    int minMul = INT_MAX;

    for(int k = i; k < j; k++){
        int result = mcmRecur(dim,i,k) +
                     mcmRecur(dim,k+1,j) +
                     dim[i-1] * dim[k] * dim[j];

        minMul = min(minMul,result);
    }

    return minMul;
}

int mcmMemo(vector<int>& dim, int i, int j,vector<vector<int>>& dp){
    if(i==j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int minMul = INT_MAX;

    for(int k = i; k < j; k++){
        int result = mcmRecur(dim,i,k) +
                     mcmRecur(dim,k+1,j) +
                     dim[i-1] * dim[k] * dim[j]; // we passed col value as i
                                                 // so i-1 = 1st matrix row
                                                 // k = 1st matrix col or 2nd matrix row
                                                 // j = 2nd matrix col

        minMul = min(minMul,result);
    }

    return dp[i][j] = minMul;
}

int matrixMultiplication(vector<int>& dim, int n){
    vector<vector<int>> dp(n,vector<int>(n,-1));
    // Every matrix has dimension i * j
    // dim represents dimension of (n-1) matrices
    // dim of (n-1)th matrix is dim[n-2] * dim[n-1]
    // dim of 1st matrix is dim[0] * dim[1]
    // That's why pass i as 1 and j as n-1
    return mcmMemo(dim,1,n-1,dp);
    // return mcmRecur(dim,1,n-1);
}

int main(){
	vector<int> arr = {10, 20, 30, 40, 50};
	int n = arr.size();
	cout<<"The minimum number of operations is "<<matrixMultiplication(arr,n);
	return 0;    
}