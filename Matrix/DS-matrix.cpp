//============================================================================
// Name        : BASIC.cpp
// Author      : Pratik Mhatre
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
#include <set>

#define MAX 6

using namespace std;

void printMat(int Mat[3][3],int row, int col)
{
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			cout<<Mat[i][j]<<" ";

	cout<<endl;
}

void printMatSnake(int Mat[3][3],int row, int col)
{
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
		{
			if(i%2)
				cout<<Mat[i][col-j-1]<<" ";
			else
				cout<<Mat[i][j]<<" ";
		}
	cout<<endl;
}

vector<vector<int>> multiplyMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
{
    // code here
    vector<vector<int>> v;

    if(A[0].size()!=B.size())
        return v;

    for(int i=0;i<A.size();i++)
    {
        vector<int>temp;
        for(int j=0;j<B[0].size();j++)
        {
            int s=0;
            for(int k=0;k<A[0].size();k++)
            {
                s+=A[i][k]*B[k][j];
            }
            temp.push_back(s);
        }
        v.push_back(temp);
    }
    return v;
}

void transponseMat(int Mat[3][3],int row, int col)
{
	for(int i=0;i<row;i++)
		for(int j=i+1;j<col;j++)
		{
			int temp=Mat[i][j];
			Mat[i][j]=Mat[j][i];
			Mat[j][i]=temp;
		}

	//printMat(Mat,3,3);
}

//Transpose and then exchange rows 0 and n-1 ..and successively
void rotateby90(int Mat[3][3],int row, int col)
{
	transponseMat(Mat,3,3);

	for(int i=0;i<row/2;i++)
	{
		for(int j=0;j<col;j++)
		{
			int temp=Mat[i][j];
			Mat[i][j]=Mat[row-i-1][j];
			Mat[row-i-1][j]=temp;
		}
	}

}
//exchange columns 0 and n-1 ..and successively
//exchange rows 0 and n-1 ..and successively
void rotateby180(int mat[3][3],int row, int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col/2;j++)
        {
            int temp=mat[i][j];
            mat[i][j]=mat[i][col-j-1];
            mat[i][col-j-1]=temp;
        }
    }
    
    for(i nt i=0;i<row/2;i++)
	{
		for(int j=0;j<col;j++)
		{
			int temp=mat[i][j];
			mat[i][j]=mat[row-i-1][j];
			mat[row-i-1][j]=temp;
		}
	}

}

void spiralPrint(int mat[3][3],int row,int col)
{
    int col_start=0;
    int col_end=col;
    int row_start=0;
    int row_end=row;

    while(col_start<col_end && row_start<row_end)
    {
        for(int i=col_start;i<col_end;i++)
            cout<<mat[row_start][i]<<" ";
        row_start++;

        for(int i=row_start;i<row_end;i++)
            cout<<mat[i][col_end-1]<<" ";
        col_end--;

        if(row_start<row_end)
        {
            for(int i=col_end-1;i>=col_start;i--)
                cout<<mat[row_end-1][i]<<" ";
            row_end--;
        }

        if(col_start<col_end)
        {
            for(int i=row_end-1;i>=row_start;i--)
                cout<<mat[i][col_start]<<" ";
            col_start++;
        }
    }
}

//Forming submatrix till the point reaching n=2
//submatrix can be formed ignoring straight and downward elements
//we need to call it recurs till 2

int Determinant(int mat[4][4],int n)
{
	int det;
	if(n==2)
	{
		return(mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0]);
	}
	else
	{
		int submat[4][4];
		for(int x=0;x<n;x++)
		{
			int subrow=0;
			for(int y=1;y<n;y++)//ignored straight elements by starting from 1
			{
				int subcol=0;
				for(int z=0;z<n;z++)
				{
					if(x==z) //ignored downward elements
						continue;
					submat[subrow][subcol]=mat[y][z];
					subcol++;
				}
				subrow++;
			}
			det=det+(mat[0][x]*pow(-1,x)*Determinant(submat,n-1));
			//cout<<det<<endl;
		}
	}
	//cout<<det<<endl;
	return det;

}

//Reduce this matrix to row echelon form
//using elementary row operations so that
//all the elements below diagonal are zero.
//Multiply the main diagonal elements of the matrix
int detNonRec(int mat[4][4],int n)
{
	double arr[n][n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			arr[i][j]=mat[i][j];

    double det=1;
    for(int i=0;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
      {

         double multiplier=arr[j][i]/arr[i][i];
         for(int k=0;k<n;k++)
         {
        	 cout<<multiplier;
    	    arr[j][k]-=arr[i][k]*multiplier;
         }
      }
    }

    for(int i=0;i<n;i++)
    {
    		for(int j=0;j<n;j++)
    			cout<<arr[i][j];
    		cout<<endl;
    }
    for(int i=0;i<n;i++)
      det*=arr[i][i];

    return det;
}

int maxHist(int hist[MAX],int n)
{
    stack<int> s;
    int i=0;
    int max_area=1;
    while(i<n)
    {
        if(s.empty()||hist[s.top()]<=hist[i])
            s.push(i++);
        else
        {
            int t=s.top();
            s.pop();

            int area=hist[t]*(s.empty()?i:i-s.top()-1);
            max_area=max(area,max_area);
        }

    }

    while(!s.empty())
    {
        int t=s.top();
        s.pop();

        int area=hist[t]*(s.empty()?i:i-s.top()-1);
        max_area=max(area,max_area);
    }

    return max_area;

}

int maxArea(int M[MAX][MAX], int n, int m) {

    int max_area=maxHist(M[0],m);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(M[i][j])
                M[i][j]+=M[i-1][j];

        }
        max_area=max(max_area,maxHist(M[i],m));
    }

    return max_area;
}

int main()
{
	int mat[3][3]={
			{1,2,3},
			{4,5,6},
			{7,8,9}
	};

	int mat2[4][4]={
			{1,0,2,-1},
			{2,1,4,-3},
			{1,0,5,0},
			{3,0,0,5}
	};

	int mat3[3][3]={
			{2,-3,1},
			{2,0,-1},
			{1,4,5}
	};

	int A[MAX][MAX] = {
	        { 0, 1, 1, 0, 1, 0},
	        { 1, 1, 1, 1, 1, 1},
	        { 1, 1, 1, 1, 1, 0},
	        { 1, 1, 1, 1, 0, 0},
	        { 1, 1, 0, 0, 0, 0},
	        { 1, 1, 0, 0, 0, 0},
	    };

	while(1)
	{
		int ch;
		cout<<"Enter Choice: ";
		cin>>ch;

		switch(ch)
		{
		case 0:
			exit(0);
		case 1:
			printMat(mat,3,3);
			break;
		case 2:
			printMatSnake(mat,3,3);
			break;
		case 3:
			transponseMat(mat,3,3);
			break;
		case 4:
			rotateby90(mat,3,3);
			break;
		case 5:
			rotateby180(mat,3,3);
			break;
		case 6:
			spiralPrint(mat,3,3);
			break;
		case 7:
			cout<< Determinant(mat2,4)<<endl;
			break;
		case 8:
			cout<< detNonRec(mat2,4)<<endl;
			break;
		case 9:
			 cout << "Maximum area is " << maxArea(A,MAX,MAX)<<endl;
			 break;

		}
	}

    return 0;
}
