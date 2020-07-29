// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell.
// The same letter cell may be used more than once.

// Example :

// Given board =

// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]
// word = "ABCCED", -> returns 1,
// word = "SEE", -> returns 1,
// word = "ABCB", -> returns 1,
// word = "ABFSAD" -> returns 1
// word = "ABCD" -> returns 0

#include <bits/stdc++.h>
using namespace std;

vector<int>rowNbr = {-1, 0, 0,1,}; 
vector<int>colNbr = { 0,-1, 1,0,};  //for four directions possible
bool isSafe(int i,int j,vector<string>&A,string B,int idx)
{
    // cout<<idx;
    if(i>=0&&i<A.size()&&j>=0&&j<A[0].size()&&A[i][j]==B[idx]) 
        return true;
    return false;
}
bool dfs(int i,int j,vector<string>&A,string B,int idx)
{
    // cout<<A[i][j]<<" "<<endl;
    if(idx==B.size())
        return true;
    for(int k=0;k<4;k++)
    {
        if(isSafe(i+rowNbr[k],j+colNbr[k],A,B,idx))
            if(dfs(i+rowNbr[k],j+colNbr[k],A,B,idx+1))
                return 1;
    }
    return false;
}

int exist(vector<string>&A,string B)
{
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            if(A[i][j]==B[0]&&dfs(i,j,A,B,1))
               return 1;
        }
    }
    return 0;
}

int main()
{
    vector<string> A = {
        {"ABCE"},
        {"SFCS"},
        {"ADEE"}
    };
    cout<<exist(A,"ABCD");
}