// Given a 2D character matrix A of size N x M, containing 'X' and 'O', capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.



// Problem Constraints
// 1 <= N, M <= 103



// Input Format
// First and only argument 2D character matrix A of size N X M.



// Output Format
// Make changes to the the input only as matrix is passed by reference.



// Example Input
// Input 1:

//  A = [  [X, X, X, X],
//         [X, O, O, X],
//         [X, X, O, X],
//         [X, O, X, X]
//      ]


// Example Output
// Output 1:

//  A = [  [X, X, X, X],
//         [X, X, X, X],
//         [X, X, X, X],
//         [X, O, X, X]
//      ]


// Example Explanation
// Explanation 1:

//  'O' in (4,2) is not surrounded by X from below.


#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector<vector<char>>&matrix)
{
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<int>rowNbr = {-1, 0, 0,1,}; 
vector<int>colNbr = { 0,-1, 1,0,};  //for four directions possible
bool isSafe(int i,int j,vector<vector<char>>&A)
{
    if(i>=0&&i<A.size()&&j>=0&&j<A[0].size()&&A[i][j]=='O') //safe and O
        return true;
    return false;
}
void dfs(int i,int j,vector<vector<char>>&A)
{
    A[i][j]='#';   //replace with a symbol to identify traversal
    for(int k=0;k<4;k++)
    {
        if(isSafe(i+rowNbr[k],j+colNbr[k],A))
            dfs(i+rowNbr[k],j+colNbr[k],A);
    }
}

void solve(vector<vector<char>>&A)
{
    for(int i=0;i<A.size();i++)
    {
        if(A[i][0]=='O')         //first col
            dfs(i,0,A);
        if(A[i][A[0].size()-1]=='O') //last col
            dfs(i,A[0].size()-1,A);
    }

    for (int i = 0; i < A[0].size(); i++)
    {
        if (A[0][i]=='O')           //first row
            dfs(0, i, A);
        if (A[A.size()-1][i] == 'O') //last row
            dfs(A.size()- 1,i,A);
    }

    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            if(A[i][j]=='#')
                A[i][j]='O';
            else
                A[i][j]='X';
        }
    }
}

int main()
{
    vector<vector<char>> A = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    // print_matrix(A);
    solve(A);
    print_matrix(A);
}