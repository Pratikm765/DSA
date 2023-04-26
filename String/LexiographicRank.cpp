#include<bits/stdc++.h>

using namespace std;

// Lexicographic rank of a String
/* Given a string str, find its rank among all its 
 * permutations when sorted lexicographically.
 * for cba = 6 and abc = 1
 * “abc”, “acb”, “bac”, “bca”, “cab”, “cba”
 */

int calFact(int n)
{
    if(n == 1)
        return 1;
    return n*calFact(n-1);
}

int smallerChar(string str, int index)
{
    int count = 0;
    for(int i = index+1; i < str.length(); i++)
    {
        if(str[index] > str[i])
            count++;
    }
    return count;
}

int findRank(string str)
{
    int rank = 1;
    int strLen = str.length();
    int mul = calFact(strLen);

    for(int i = 0; i < strLen; i++)
    {
        mul/= (strLen-i);
        int count = smallerChar(str,i);
        rank += (mul*count);
    }

    return rank;
}

int main ()
{
    string str = "cba";
    cout << findRank(str);
    return 0;
}