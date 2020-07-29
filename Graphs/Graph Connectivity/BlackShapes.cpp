// Given N x M character matrix A of O's and X's, where O = white, X = black.

// Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)



// Input Format:

//     The First and only argument is a N x M character matrix.
// Output Format:

//     Return a single integer denoting number of black shapes.
// Constraints:

//     1 <= N,M <= 1000
//     A[i][j] = 'X' or 'O'
// Example:

// Input 1:
//     A = [ OOOXOOO
//           OOXXOXO
//           OXOOOXO  ]
// Output 1:
//     3
// Explanation:
//     3 shapes are  :
//     (i)    X
//          X X
//     (ii)
//           X
//     (iii)
//           X
//           X
// Note: we are looking for connected shapes here.

// XXX
// XXX
// XXX
// is just one single connected black shape.
#include <bits/stdc++.h>
using namespace std;



vector<int>rowNbr = {-1, 0, 0,1,}; 
vector<int>colNbr = { 0,-1, 1,0,};  //for four directions possible
bool isSafe(int i,int j,vector<string>&A)
{
    if(i>=0&&i<A.size()&&j>=0&&j<A[0].size()&&A[i][j]=='X')
        return true;
    return false;
}
void dfs(int i,int j,vector<string>&A,vector<vector<bool>>&visited)
{
    visited[i][j]=true;
    for(int k=0;k<4;k++)
    {
        if(isSafe(i+rowNbr[k],j+colNbr[k],A)&&!visited[i+rowNbr[k]][j+colNbr[k]])
            dfs(i+rowNbr[k],j+colNbr[k],A,visited);
    }
}
int black(vector<string> &A) {
    vector<vector<bool>>visited(A.size(),vector<bool>(A[0].size(),false));
    int res=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            if(A[i][j]=='X'&&!visited[i][j])
            {
                dfs(i,j,A,visited);
                res++;
            }
        }
    }
    return res;
}

int main()
{
    vector<string> A = { "OOOXOOO",
                         "OOXXOXO",
                         "OXOOOXO"};
    cout<<black(A); //op 3
}