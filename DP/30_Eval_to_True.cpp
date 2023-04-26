#include <bits/stdc++.h>
using namespace std;

int SolveRecur(string x, int i, int j, bool isTrue){
    if(i >= j){
        if(isTrue)
            return x[i] == 'T';
        else
            return x[i] == 'F';
    }
    int result = 0;
    for(int k = i+1; k < j; k += 2){
        int lt = SolveRecur(x,i,k-1,true);
        int lf = SolveRecur(x,i,k-1,false);
        int rt = SolveRecur(x,k+1,j,true);
        int rf = SolveRecur(x,k+1,j,false);

        if(x[k] == '|'){
            if(isTrue == true)
                result += lt*rt + lt*rf + lf*rt;
            else
                result += lf*rf;
        }
        else if(x[k] == '&'){
            if(isTrue == true)
                result += lt*rt;
            else
                result += lf*rf + lt*rf + lf*rt;
        }
        else if(x[k] == '^'){
            if(isTrue == true)
                result += lt*rf + lf*rt;
            else
                result += lf*rf + lt*rt;
        }
    }
    return result;
}

unordered_map<string,int> dp;

int SolveMemo(string x, int i, int j, bool isTrue){
    string str = to_string(i) + " " + to_string(j) + " " + (isTrue ? "T":"F");
    if(i >= j){
        if(isTrue)
            return x[i] == 'T'; // return true if expression is true
        else                    // if we are evaluating True value
            return x[i] == 'F'; // return true if expression is false
    }                           // if we are evaluating False value

    if(dp.find(str) != dp.end())
        return dp[str];

    int result = 0;
    // starting from i+1 with 2's increment
    // because operators will be present at even position
    // T & F | T
    for(int k = i+1; k < j; k += 2){
        // for some operators to evaluate true sometimes
        // false is required like EXOR operator
        // so evaluate both the cases for both partitions
        int lt = SolveRecur(x,i,k-1,true);
        int lf = SolveRecur(x,i,k-1,false);
        int rt = SolveRecur(x,k+1,j,true);
        int rf = SolveRecur(x,k+1,j,false);

        if(x[k] == '|'){
            if(isTrue == true)
                result += lt*rt + lt*rf + lf*rt; // TT + TF + FT
            else
                result += lf*rf; // FF
        }
        else if(x[k] == '&'){
            if(isTrue == true)
                result += lt*rt; // TT
            else
                result += lf*rf + lt*rf + lf*rt; // FF + TF + FT
        }
        else if(x[k] == '^'){
            if(isTrue == true)
                result += lt*rf + lf*rt; // TF + FT
            else
                result += lf*rf + lt*rt; // FF + TT
        }
    }
    return dp[str] = result;
}

int main() {
	string X; cin >> X;
	cout << SolveRecur(X, 0, X.length() - 1, true) << endl;
	cout << SolveMemo(X, 0, X.length() - 1, true) << endl;
	return 0;
}