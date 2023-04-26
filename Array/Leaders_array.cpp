#include<bits/stdc++.h>

using namespace std;

// Leaders Array
/* Write a program to print all the LEADERS in the array. 
 * An element is leader if it is greater than all the 
 * elements to its right side. And the rightmost element 
 * is always a leader. For example in the 
 * array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2. 
 */

void LeadersArray(int arr[], int n)
{
    vector<int> v;
    int curr = arr[n-1];
    v.push_back(curr);

    for(int i = n-2; i >= 0; i--)
    {   
        if(curr<arr[i])
        {
            curr = arr[i];
            v.push_back(curr);
        }
    }

    reverse(v.begin(),v.end());

    for(int t: v)
        cout << t << " ";
    cout<<endl;
}

int main()
{
    int arr[6] = {16, 17, 4, 3, 5, 2};
    LeadersArray(arr,6);

    return 0;
}