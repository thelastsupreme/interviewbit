// Problem Description

// Given a binary matrix A of size N x M.

// Cells which contain 1 are called filled cell and cell that contain 0 are called empty cell.

// Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally.

// If one or more filled cells are also connected, they form a region. Find the length of the largest region.

// .



// Problem Constraints
// 1 <= N, M <= 102

// A[i][j]=0 or A[i][j]=1



// Input Format
// First argument is a 2D binary matrix Aof size  N x M.



// Output Format
// Return a single interger denoting the length of largest region.



// Example Input
// Input 1:

//  A = [  [0, 0, 1, 1, 0]
//         [1, 0, 1, 1, 0]
//         [0, 1, 0, 0, 0]
//         [0, 0, 0, 0, 1]
//     ]
// Input 2:

//  A = [  [1, 1, 1]
//         [0, 0, 1]
//     ]


// Example Output
// Output 1:

//  6
// Output 2:

//  4


// Example Explanation
// Explanation 1:

//  The largest region is denoted by red color in the matrix:
//     00110
//     10110
//     01000
//     00001
// Explanation 2:

//  The largest region is:
//     111
//     001

#include <bits/stdc++.h>
using namespace std;

vector<int>rowNbr = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
vector<int>colNbr = { -1, 0, 1, -1, 1, -1, 0, 1 };
bool isSafe(int i,int j,vector<vector<int>>&A,vector<vector<bool>>&visited)
{
    if(i>=0&&i<A.size()&&j>=0&&j<A[0].size()&&A[i][j]&&!visited[i][j]) 
        return true;
    return false;
}
int dfs(int i,int j,vector<vector<int>>&A,vector<vector<bool>>&visited)
{
    // cout<<i<<" "<<j<<endl;
    visited[i][j]=true;
    int count=1;
    for(int k=0;k<8;k++)
    {
        if(isSafe(i+rowNbr[k],j+colNbr[k],A,visited))
            count+=dfs(i+rowNbr[k],j+colNbr[k],A,visited);
    }
    return count;
}


int solve(vector<vector<int>>&A)
{
    vector<vector<bool>>visited(A.size(),vector<bool>(A[0].size(),false));
    int res=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            if(A[i][j]&&!visited[i][j])
                res=max(res,dfs(i,j,A,visited));
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> A = {{0, 0, 1, 1, 0},
                             {1, 0, 1, 1, 0},
                             {0, 1, 0, 0, 0},
                             {0, 0, 0, 0, 1}};
    cout<<solve(A);
}