// Given a 2D integer array A of size M x N, you need to find a path from top left to bottom right which minimizes the sum of all numbers along its path.

// NOTE: You can only move either down or right at any point in time.

// Input Format
// First and only argument is an 2D integer array A of size M x N.

// Output Format
// Return a single integer denoting the minimum sum of a path from cell (1, 1) to cell (M, N).

// Example Input
// Input 1:

//  A = [  [1, 3, 2]
//         [4, 3, 1]
//         [5, 6, 1]
//      ]


// Example Output
// Output 1:
//  9

// Example Explanation
// Explanation 1:

//  The path is 1 -> 3 -> 2 -> 1 -> 1
//  So ( 1 + 3 + 2 + 1 + 1) = 8
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minPathSum(vector<vector<int> > &A) {
    
    for(int i=1;i<A.size();i++){
        A[i][0]+=A[i-1][0];
    }
    for(int j=1;j<A[0].size();j++){
        A[0][j]+=A[0][j-1];
    }
    for(int i=1;i<A.size();i++){
        for(int j=1;j<A[0].size();j++){
            A[i][j]+=min(A[i-1][j],A[i][j-1]);
        }
    }
    return A[A.size()-1][A[0].size()-1];
}

int main(){
    vector<vector<int>>A = {{1, 3, 2},{4, 3, 1},{5, 6, 1}};
    cout<<minPathSum(A);
}