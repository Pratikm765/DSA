#include<bits/stdc++.h>

using namespace std;

// String Subsequences
/* Given a string, we have to find out all subsequences 
 * of it. A String is a subsequence of a given String, 
 * that is generated by deleting some character of a 
 * given string without changing its order.
 */

void subsetsAre(string s, string curr, int i)
{
    if(s.length() == i)
    {
        cout << curr <<endl;
        return;
    }

    subsetsAre(s,curr,i+1);
    subsetsAre(s,curr+s[i],i+1);
}

int main()
{
    string str ="ABC";
	subsetsAre(str,"",0);
    return 0;
}