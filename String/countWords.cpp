#include <bits/stdc++.h>
using namespace std;
 
int countWords(string str)
{
    stringstream ss(str);
    string word;
    int count = 0;

    while(ss >> word)
    {
        count++;
    }

    return count;
}
 
int main()
{
    string str = "Geeks for Geeks";
    cout << countWords(str);
    return 0;
}