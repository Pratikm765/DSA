#include <bits/stdc++.h>
using namespace std;
 
string RemoveSpaces(string str)
{
    stringstream ss(str);
    string word;
    string result;

    while(ss >> word)
    {
        result += word;
    }

    return result;
}
 
int main()
{
    string str = "Geeks for Geeks";
    cout << RemoveSpaces(str);
    return 0;
}