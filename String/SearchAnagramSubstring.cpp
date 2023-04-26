#include<bits/stdc++.h>

using namespace std;
bool compareStr(int arr1[], int arr2[])
{
    for(int i = 0; i < 256; i++)
    {
        if(arr1[i] != arr2[i])
            return false;
    }
    return true;
}
void searchAnagramSubstr(string& pat, string& txt)
{
    int countPat[256] = {0};
    int countTxt[256] = {0};

    for(int i = 0; i < pat.length(); i++)
    {
        countPat[pat[i]]++;
        countTxt[txt[i]]++;
    }

    for(int i = pat.length(); i < txt.length(); i++)
    {
        if(compareStr(countTxt,countPat))
            cout << "Pattern Anagram exists from " 
                << i-pat.length() << " " << i-1 << endl;
        countTxt[txt[i-pat.length()]]--;
        countTxt[txt[i]]++;
    }

    if(compareStr(countTxt,countPat))
        cout << "Pattern Anagram exists from " 
            << txt.length()-pat.length() << " " 
            << txt.length()-1 << endl;
}

int main()
{
    string txt = "BACDGABCDA";
    string pat = "ABCD";
    searchAnagramSubstr(pat, txt);
    return 0;
}