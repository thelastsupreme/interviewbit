// Given a 2D binary matrix A of size  N x M  find the area of maximum size square sub-matrix with all 1's.



// Problem Constraints
// 1 <= N, M <= 103

// A[i][j] = 1 or A[i][j] = 0



// Input Format
// First argument is an 2D matrix A of size N x M.



// Output Format
// Output the area of maximum size square sub-matrix in A with all 1's.



// Example Input
// Input 1:

//  A = [

//         [0, 1, 1, 0, 1],

//         [1, 1, 0, 1, 0],

//         [0, 1, 1, 1, 0],

//         [1, 1, 1, 1, 0],

//         [1, 1, 1, 1, 1],

//         [0, 0, 0, 0, 0]
//      ]
// Input 2:

//  A = [

//        [1, 1],
//        [1, 1]
//      ]


// Example Output
// Output 1:

//  9
// Output 2:

//  4


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            if (A[i][j])
                A[i][j] = 1 + min({A[i - 1][j], A[i - 1][j - 1], A[i][j - 1]});
        }

    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = max(ans, A[i][j]);

    ans *= ans;
    return ans;
}

int main(){
vector<vector<int>>A={{0, 1, 1, 0, 1},{1, 1, 0, 1, 0},{0, 1, 1, 1, 0},{1, 1, 1, 1, 0},{1, 1, 1, 1, 1},{0, 0, 0, 0, 0}};
cout<<solve(A);
}