#include<bits/stdc++.h>

using namespace std;

/* You need to print this sentence after following amendments:
 * (i) Put a single space between these words
 * (ii) Convert the uppercase letters to lowercase.
 */

string AmendSentence(string str)
{
    string result;
    int j = 0;
    for(int i = 1; i < str.length(); i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            result += str.substr(j,i-j)+' ';
            j = i;
        }
    }
    result += str.substr(j);
    return result;
}

int main()
{
    string s = "BruceWayneIsBatman";
    cout << AmendSentence(s);
    return 0;
}