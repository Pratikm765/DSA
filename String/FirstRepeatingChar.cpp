#include<bits/stdc++.h>

using namespace std;

// First repeating Character
/* Given a string, find the first repeated character 
 * in it. We need to find the character that occurs 
 * more than once and whose index of second occurrence 
 * is smallest.
 */
char firstRepeating(string &str)
{
    unordered_set<char> s;
    for(int i = 0; i < str.length(); i++)\
    {
        char c = str[i];

        if(s.find(c) != s.end())  
            return c;
        else
            s.insert(c);
    }
    return '\0';
}

/* We need to find the character that occurs more 
 * than once and whose index of first occurrence 
 * is smallest.
 */
char firstRepeatingAlt(string &str)
{
    unordered_map<char,int> m;
    int Min_index = 256;

    for(int i = 0; i < str.length(); i++)\
    {
        char c = str[i];
        if(m.find(c) != m.end())  
        {
            Min_index = min(Min_index,m[c]);
        }
        else
        {
            m[c] = i;
        }
    }
    return Min_index == 256 ? '\0' : str[Min_index];
}

int main ()
{
    string str = "geeksforgeeks";
    cout << firstRepeatingAlt(str);
    return 0;
}