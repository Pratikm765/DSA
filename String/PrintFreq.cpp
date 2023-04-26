#include <bits/stdc++.h>
using namespace std;
 
// Function to print frequency of each word
void printFrequency(string str)
{
    unordered_map<string,int> mp;
    stringstream ss(str);
    string word;

    while(ss >> word)
    {
        mp[word]++;
    }

    unordered_map<string,int>::iterator it;

    for(it=mp.begin(); it!=mp.end(); it++)
    {
        cout << it->first << " --> " << it->second << endl;
    }
}

int main()
{
    string str = "learning to code is learning to create and innovate";

    printFrequency(str);
    return 0;
}