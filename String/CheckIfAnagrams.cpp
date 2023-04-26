#include<bits/stdc++.h>

using namespace std;

// Check if strings are anagrams.
/* An anagram of a string is another string that 
 * contains the same characters, only the order 
 * of characters can be different. 
 * For example, “abcd” and “dabc” are an anagram of each other.
 */

bool areAnagram(string str1, string str2)
{
    int NO_OF_CHAR[256] = {0};
    int i;

    for(i = 0; str1[i] && str2[i]; i++)
    {
        NO_OF_CHAR[str1[i]]++;
        NO_OF_CHAR[str2[i]]--;
    }

    if(str1[i] || str2[i])
        return false;

    for(i = 0; i < 256; i++)
    {
        if(NO_OF_CHAR[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    string str1 = "LISTEN";
    string str2 = "SILENT";
 
    if (areAnagram(str1, str2))
        cout << "The two strings are anagram of each other";
    else
        cout << "The two strings are not anagram of each "
                "other";
 
    return 0;
}