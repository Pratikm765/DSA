#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string X, int i, int j) { // function to check either a string is palindrome or not 
	while (i <= j) {
		if (X[i] != X[j])
			return false;
		i++, j--;
	}

	return true;
}

int SolveRecur(string X, int i, int j) {
	if (i >= j || isPallindrome(X, i, j))
		return 0;

	int ans = INT_MAX;
	for (int k = i; k < j; k++) {
		int temp_ans = 1 + SolveRecur(X, i, k) + SolveRecur(X, k + 1, j);
		ans = min(ans, temp_ans);
	}
	return ans;
}

int SolveMemo(string X, int i, int j,vector<vector<int>>& dp) {
	if (i >= j)
		return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(isPallindrome(X, i, j))
    {
        dp[i][j] = 0;
        return 0;
    }

	int ans = INT_MAX;
    // Divide every string into the two parts
    // Suppose str = "abcd"
    // start from a & bcd, then ab & cd, then abc & d.
    // i to k & k+1 to j that's why k starts from i to j-1
	for (int k = i; k < j; k++) {
        int lt = 0;
        if(dp[i][k] == -1)
            lt = SolveRecur(X, i, k);
        else
            lt = dp[i][k];

        int rt = 0;
        if(dp[k+1][j] == -1)
            rt = SolveRecur(X, k + 1, j);
        else
            rt = dp[k+1][j];

		int temp_ans = 1 + lt + rt;

		ans = min(ans, temp_ans);
	}
	return dp[i][j] = ans;
}
// for str = ababc
// first divided int a & babc
// Then babc into bab & c.

int main() {
	string X; cin >> X;

	cout << SolveRecur(X, 0, X.length() - 1) << endl;

    vector<vector<int>> dp(X.length(),vector<int>(X.length(),-1));
    cout << SolveMemo(X, 0, X.length() - 1,dp) << endl;
	return 0;
}