// Given an integer array A of size N. You have to merge all the elements of the array into one with the minimum possible cost.

// The rule for merging is as follows:

// Choose any two adjacent elements of the array with values say X and Y and merge them into a single element with value (X + Y) paying a total cost of (X + Y).
// Return the minimum possible cost of merging all elements.



// Problem Constraints
// 1 <= N <= 200

// 1 <= A[i] <= 103



// Input Format
// First and only argument is an integer array A of size N.



// Output Format
// Return an integer denoting the minimum cost of merging all elements.



// Example Input
// Input 1:

//  A = [1, 3, 7]
// Input 2:

//  A = [1, 2, 3, 4]


// Example Output
// Output 1:

//  15
// Output 2:

//  19


// Example Explanation
// Explanation 1:

//  All possible ways of merging:
//  a) {1, 3, 7} (cost = 0) -> {4, 7} (cost = 4) -> {11} (cost = 4+11 = 15)
//  b) {1, 3, 7} (cost = 0) -> {1, 10} (cost = 10) -> {11} (cost = 10+11 = 21)
//  Thus, ans = 15

#include <bits/stdc++.h>
using namespace std;

//top down
int merge(int i, int j, vector<int> &A, vector<vector<int>> &T)
{

    if (T[i][j] != -1) // Already Visited
        return T[i][j];
    if (i == j) // Base case => For 1 element cost = 0.
        T[i][j] = 0;
    else if (i == j - 1) // Base Case => For 2 elements cost = sum of two elements.
        T[i][j] = A[i] + A[j];
    else
    {
        int val = INT_MAX;
        int sum = A[j];
        for (int k = i; k < j; k++)
        {
            sum += A[k];
            val = min(val, merge(i, k, A, T) + merge(k + 1, j, A, T));
        }
        T[i][j] = val + sum;
    }

    return T[i][j];
}

int solve(vector<int> &A)
{

    int n = A.size();
    vector<vector<int>> T(n, vector<int>(n, -1));

    int soln = merge(0, n - 1, A, T);
    return soln;
}
//bottom up

int solve_1(vector<int> &A)
{
    int n = A.size();
    if (n == 0)
        return 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> prefix_sum(n, 0);
    prefix_sum[0] = A[0];
    for (int i = 1; i < n; i++)
        prefix_sum[i] = prefix_sum[i - 1] + A[i];

    for (int len = 1; len < n; len++)
    {
        for (int i = 0; i < n - len; i++)
        {
            int j = i + len;
            int add = INT_MAX;
            for (int k = i; k < j; k++)
                add = min(add, dp[i][k] + dp[k + 1][j]);
            dp[i][j] = (prefix_sum[j] - ((i == 0) ? 0 : prefix_sum[i - 1])) + add;
        }
    }
    return dp[0][n - 1];
}