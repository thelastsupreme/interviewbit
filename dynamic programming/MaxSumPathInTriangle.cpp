// Given a 2D integer array A of size  N * N  representing a triangle of numbers.

// Find the maximum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

// NOTE:

// Adjacent cells to cell (i,j) are only (i+1,j) and (i+1,j+1)
// Row i contains i integer and n-i zeroes for all i in [1,n] where zeroes represents empty cells.


// Problem Constraints
// 0 <= N <= 1000

// 0 <= A[i][j] <= 1000



// Input Format
// First and only argument is an 2D integer array A of size N * N.



// Output Format
// Return a single integer denoting the maximum path sum from top to bottom in the triangle.



// Example Input
// Input 1:

//  A = [
//         [3, 0, 0, 0]
//         [7, 4, 0, 0]
//         [2, 4, 6, 0]
//         [8, 5, 9, 3]
//      ]
// Input 2:

//  A = [
//         [8, 0, 0, 0]
//         [4, 4, 0, 0]
//         [2, 2, 6, 0]
//         [1, 1, 1, 1]
//      ]


// Example Output
// Output 1:

//  23
// Output 2:

//  19


// Example Explanation
// Explanation 1:

//  Given triangle looks like:  3
//                              7 4
//                              2 4 6
//                              8 5 9 3
//         So max path is (3 + 7 + 4 + 9) = 23
// Explanation 1:

//  Given triangle looks like:  8
//                              4 4
//                              2 2 6
//                              1 1 1 1
//         So max path is (8 + 4 + 6 + 1) = 19

#include<iostream>
#include<vector>
using namespace std;

int solve(vector<vector<int> > &A) {
    for(int i=0;i<A.size();i++)
        A[i].erase(A[i].begin()+i+1,A[i].end()); //trim of all zeroes
        
    for(int i=1;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            if(j==0){
                A[i][j]+=A[i-1][j];
            }else if(j==A[i].size()-1){
                A[i][j]+=A[i-1][A[i-1].size()-1];
            }else{
                A[i][j]+=max(A[i-1][j],A[i-1][j-1]);
            }
        }
    }
    
    int maxx=INT32_MIN;
    for(int i=0;i<A[A.size()-1].size();i++){
        maxx=max(maxx,A[A.size()-1][i]);
    }
    return maxx;
}
int main(){
    vector<vector<int>>A={{9},{3,8},{0,2,4},{8,3,9,0},{5,2,2,7,3},{7,9,0,2,3,9},{9,7,0,3,9,8,6},{ 5,7,6,2,7,0,3,9}};
    cout<<solve(A);
}