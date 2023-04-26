#include<bits/stdc++.h>
using namespace std;

int solveRecur(int f,int e){
    if(e == 1)
        return f;
    if(f == 0 || f == 1)
        return f;

    int MinAttempts = INT_MAX;

    for(int k = 1; k <= f; k++){
        int temp = 1 + max(solveRecur(k-1,e-1),solveRecur(f-k,e));
        MinAttempts = min(MinAttempts,temp);
    }
    return MinAttempts;
}

int solveMemo(int f,int e,vector<vector<int>>& dp){
    if(e == 1)
        return f;
    if(f == 0 || f == 1)
        return f;

    if(dp[f][e] != -1)
        return dp[f][e];

    int MinAttempts = INT_MAX;

    for(int k = 1; k <= f; k++){
        int temp = 1 + max(solveRecur(k-1,e-1),solveRecur(f-k,e));
        MinAttempts = min(MinAttempts,temp);
    }
    return dp[f][e] = MinAttempts;
}

int solveTab(int f,int e){
    int dp[f+1][e+1];

    for(int i = 1; i <= e; i++){
        dp[0][i] = 0;
        dp[1][i] = 1;
    }

    for(int i = 1; i <= f; i++){
        dp[i][1] = i;
    }

    for (int i = 2; i <= f; i++) {
        for (int j = 2; j <= e; j++) {
            dp[i][j] = INT_MAX;
            for(int k = 1; k <= i; k++){
                int temp = 1 + max(dp[k-1][j-1],dp[i-k][j]);
                dp[i][j] = min(dp[i][j],temp);
            }
        }
    }
    return dp[f][e];
}

int main(){
    int floors, eggs;
    cin >> floors >> eggs;

    cout << solveRecur(floors,eggs);

    vector<vector<int>> dp(floors+1,vector<int>(eggs+1,-1));
    cout << solveMemo(floors,eggs,dp);

    cout << solveTab(floors,eggs);

}