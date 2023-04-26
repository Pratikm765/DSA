#include<bits/stdc++.h>
using namespace std;

void countIslandsUtil(vector<vector<int>>& M, int i, int j, int col, int row, vector<vector<bool>>& visited){
    if((i<0) || (j<0) || (i>(col-1)) || (j>(row-1)) || 
       (M[i][j] == 0) || (visited[i][j] == true))
    return;

    visited[i][j] = true;
    countIslandsUtil(M,i+1,j,col,row,visited);
    countIslandsUtil(M,i-1,j,col,row,visited);
    countIslandsUtil(M,i,j+1,col,row,visited);
    countIslandsUtil(M,i,j-1,col,row,visited);

}

int countIslands(vector<vector<int>>& M){
    vector<vector<bool>> visited(M.size(),vector<bool>(M[0].size(),false));
    int count = 0;

    for(int i = 0; i < M.size(); i++)
    {
        for(int j = 0; j < M[0].size(); j++)
        {
            if((M[i][j] == 1) && (visited[i][j] == false))
            {
                count++;
                countIslandsUtil(M,i,j,M.size(),M[0].size(),visited);
            }   
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> M = { { 1, 1, 0, 0, 0 },
                               { 0, 1, 0, 0, 1 },
                               { 1, 0, 0, 1, 1 },
                               { 0, 0, 0, 0, 1 },
                               { 1, 1, 1, 0, 1 } };
 
    cout << "Number of islands is: " << countIslands(M);
    return 0;
}
 