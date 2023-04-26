
#include <bits/stdc++.h>
using namespace std;

// scrambled strings for "ate"
// ate tea aet tae eat eta
// partition and swap

bool SolveRecur(string X, string Y) {
	if (X.compare(Y) == 0)
		return true;
	if (X.length() <= 1)
		return false;

	int n = X.length();
	int flag = false;
	for (int i = 1; i <= n - 1; i++) {
        // string x partitioned = xl1...xl2 and xr1...xr2
        // string y partitioned = yl1...yl2 and yr1...yr2
        // for swapped case compare : xl1...xl2 and yr1...yr2
        // for swapped case compare : xr1...xr2 and yl1...yl2  
        // for not swapped case compare : xl1...xl2 and yl1...yl2
        // for not swapped case compare : xr1...xr2 and yr1...yr2
		if ((SolveRecur(X.substr(0, i), Y.substr(n - i, i)) && SolveRecur(X.substr(i), Y.substr(0, n - i))) || // these are two condition for swapping and not swapping the string 
		    (SolveRecur(X.substr(0, i), Y.substr(0, i)) && SolveRecur(X.substr(i), Y.substr(i)))) {
			flag = true; // change the  flag to true and break 
			break;
		}
	}
	return flag;
}

unordered_map<string,int> dp;

bool SolveMemo(string X, string Y) {
    string str = X + " " + Y;
    if(dp.find(str) != dp.end())
        return dp[str];

	if (X.compare(Y) == 0)
        return dp[str] = true;

	if (X.length() <= 1)
		return dp[str] = false;

	int n = X.length();
	int flag = false;
	for (int i = 1; i <= n - 1; i++) {
        // string x partitioned = xl1...xl2 and xr1...xr2
        // string y partitioned = yl1...yl2 and yr1...yr2
        // for swapped case compare : xl1...xl2 and yr1...yr2
        // for swapped case compare : xr1...xr2 and yl1...yl2  
        // for not swapped case compare : xl1...xl2 and yl1...yl2
        // for not swapped case compare : xr1...xr2 and yr1...yr2
		if ((SolveMemo(X.substr(0, i), Y.substr(n - i, i)) && SolveMemo(X.substr(i), Y.substr(0, n - i))) || // these are two condition for swapping and not swapping the string 
		    (SolveMemo(X.substr(0, i), Y.substr(0, i)) && SolveMemo(X.substr(i), Y.substr(i)))) {
			flag = true; // change the  flag to true and break 
			break;
		}
	}
	return dp[str] = flag;
}


int main() {
	string X, Y; cin >> X >> Y;

	if (X.length() != Y.length())
		cout << "No\n";
	else
		SolveRecur(X, Y) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}