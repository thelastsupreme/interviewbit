// Problem Description

// Given an integer array A of size N.

// You are also given an integer B, you need to find whether their exist a subset in A whose sum equal B.

// If there exist a subset then return 1 else return 0.



// Problem Constraints
// 1 <= N <= 100

// 1 <= A[i] <= 100

// 1 <= B <= 105



// Input Format
// First argument is an integer array A.

// Second argument is an integer B.



// Output Format
// Return 1 if there exist a subset with sum B else return 0.



// Example Input
// Input 1:

//  A = [3, 34, 4, 12, 5, 2]
//  B = 9
// Input 2:

//  A = [3, 34, 4, 12, 5, 2]
//  B = 30


// Example Output
// Output 1:

//  1
// Output 2:

//  0


// Example Explanation
// Explanation 1:

//  There is a subset (4, 5) with sum 9.
// Explanation 2:

//  There is no subset that add up to 30.

#include <bits/stdc++.h>
using namespace std;

bool subsetsum(vector<int>A,int sum){
    vector<vector<bool>>t(A.size()+1,vector<bool>(sum+1,false));

    for(int i=0;i<A.size()+1;i++){
        t[i][0]=true; //since subset null can always genertate a sum zero
    }

    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<sum+1;j++){
            if(A[i-1]<=j){
                t[i][j]=t[i-1][j]||t[i-1][j-A[i-1]];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    // for(int i=0;i<A.size()+1;i++){
    //     for(int j=0;j<sum+1;j++){
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return t[A.size()][sum];
}
int solve(vector<int> &A, int B) {
    return subsetsum(A,B);
}