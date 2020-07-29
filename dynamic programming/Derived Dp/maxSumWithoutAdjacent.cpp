// Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers
// is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

// Note: You can choose more than 2 numbers.

// Input Format:

// The first and the only argument of input contains a 2d matrix, A.
// Output Format:

// Return an integer, representing the maximum possible sum.
// Constraints:

// 1 <= N <= 20000
// 1 <= A[i] <= 2000
// Example:

// Input 1:
//     A = [   [1]
//             [2]    ]

// Output 1:
//     2

// Explanation 1:
//     We will choose 2.

// Input 2:
//     A = [   [1, 2, 3, 4]
//             [2, 3, 4, 5]    ]
    
// Output 2:
//     We will choose 3 and 5.

#include<iostream>
#include<vector>
using namespace std;

int adjacent(vector<vector<int> > &A) {
    vector<int>temp(A.size()+1,0);
    temp[1]=max(A[0][0],A[1][0]);
    temp[2]=max(A[0][1],A[1][1]);
    for(int i=3;i<=A[0].size();i++)
    {
        temp[i]=max(A[0][i-1],A[1][i-1])+max(temp[i-2],temp[i-3]);
    }
    return max(temp[A[0].size()],temp[A[0].size()-1]);
}

int main(){
    vector<vector<int>>A={{1,2,3,4},{2,3,4,5}};
    cout<<adjacent(A);
}