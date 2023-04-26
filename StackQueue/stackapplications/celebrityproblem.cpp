#include <bits/stdc++.h>
using namespace std;

#define N 4

bool MATRIX[N][N] = { { 0, 0, 1, 0 },
					{ 0, 0, 1, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 1, 0 } };

bool knows(int a, int b) { return MATRIX[a][b]; }

int findCelebrity(int n)
{
    stack<int> st;

    for(int i = 0; i < n; i++){
        st.push(i);
    }

    while(st.size() > 1)
    {
        int t1 = st.top();
        st.pop();
        int t2 = st.top();
        st.pop();
        
        if(knows(t1,t2)){
            st.push(t2);
        }
        else
        {
            st.push(t1);
        }
    }
    int celebrity = st.top();

    for(int i = 0; i < n; i++){
        if((celebrity != i) && 
           (!knows(i,celebrity) || knows(celebrity,i)))
            return -1;
    }
	return celebrity;
}

int main()
{
	int n = 4;
	int id = findCelebrity(n);
	id == -1 ? cout << "No celebrity"
			: cout << "Celebrity ID " << id;
	return 0;
}
