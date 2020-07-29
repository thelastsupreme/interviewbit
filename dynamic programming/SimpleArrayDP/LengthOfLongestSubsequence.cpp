// Problem Description

// Given an 1D integer array A of length N, find the length of longest subsequence which is first increasing then decreasing.

// Problem Constraints
// 0 <= N <= 3000

// -107 <= A[i] <= 107

// Input Format
// The first and the only argument contains an integer array A.

// Output Format
// Return an integer representing the answer as described in the problem statement.

// Example Input
// Input 1:

//  A = [1, 2, 1]
// Input 2:

//  A = [1, 11, 2, 10, 4, 5, 2, 1]


// Example Output
// Output 1:

//  3
// Output 2:

//  6

// Example Explanation
// Explanation 1:

//  [1, 2, 1] is the longest subsequence.
// Explanation 2:

//  [1 2 10 4 2 1] is the longest subsequence.
#include <bits/stdc++.h>
using namespace std;


int longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    int inc[n];
    int dec[n];
    int ct = 0;

    inc[0] = 1;
    for(int i=1; i<n; i++)
    {
        inc[i] = 1;
        for(int j=i-1; j>=0; j--)
        {
            if(A[i] > A[j] && inc[i] < inc[j] + 1)
                inc[i] = inc[j] + 1;
        }
    }

    dec[n-1] = 1;
    for(int i=n-2; i>=0; i--)
    {
        dec[i] = 1;
        for(int j=i+1; j<n; j++)
        {
            if(A[i] > A[j] && dec[i] < dec[j] + 1)
                dec[i] = dec[j] + 1;
        }
    }

    int mx = 0;
    for(int i=0; i<n; i++)
        mx = max(mx, inc[i] + dec[i] - 1);

    return mx;
}
