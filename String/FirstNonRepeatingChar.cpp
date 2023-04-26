#include<bits/stdc++.h>

using namespace std;

// First Non repeating Character
/* Given a string S consisting of lowercase Latin Letters, 
 * the task is to find the first non-repeating character in S.
 */
char firstNonRepeating(string &str)
{
    pair<int,int> freq[256];

    for(int i = 0; i < str.length(); i++)
    {
        freq[str[i]].first = i;
        freq[str[i]].second++;
    }

    int index = INT_MAX;
    for(int i = 0; i < 256; i++)
    {
        if(freq[i].second == 1)
        {
            index = min(index, freq[i].first);
        }
    }    

    return index == INT_MAX ? '\0' : str[index];
}

int main ()
{
    string str = "geeksforgeeksfor";
    cout << firstNonRepeating(str);
    return 0;
}