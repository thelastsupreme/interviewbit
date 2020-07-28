// Problem Description

// Given an array of integers A of size N in which ith element is the price of the stock on day i.

// You can complete atmost B transactions.

// Find the maximum profit you can achieve.

// NOTE: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).



// Problem Constraints
// 1 <= N <= 500

// 0 <= A[i] <= 106

// 0 <= B <= 109



// Input Format
// The First argument given is the integer array A.

// The Second argument is integer B.



// Output Format
// Return the maximum profit you can achieve by doing atmost B transactions.



// Example Input
// Input 1:

//  A = [2, 4, 1]
//  B = 2
// Input 2:

//  A = [3, 2, 6, 5, 0, 3]
//  B = 2


// Example Output
// Output 1:

//  2
// Output 2:

//  7


// Example Explanation
// Explanation 1:

//  Buy on day 1 (price = 2) and sell on day 2 (price = 4), 
//  Profit = 4 - 2 = 2
// Explanation 2:

//  Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6 - 2 = 4.
//  Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3 - 0 = 3.
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int n=A.size();
    if(B>n) B=n;
    vector<vector<int>> buy(B+1,vector<int>(n+1,0));
    vector<vector<int>> profit(B+1,vector<int>(n+1,0));
    for(int i=0;i<=B;++i) buy[i][0]=INT_MAX;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<B;++j)
        {
            buy[j+1][i+1]=min(buy[j+1][i],A[i]-profit[j][i]);
            profit[j+1][i+1]=max(profit[j+1][i],A[i]-buy[j+1][i+1]);
        }
    }
    return profit[B][n];
}

int solve_editorial(vector<int> &A, int B) {
    int n=A.size();
    if(B>=n/2)
    {
        int profit=0;
        for(int i=1;i<n;i++)
        if(A[i]>A[i-1])
        profit+=A[i]-A[i-1];
        return profit;
    }
    vector<int>buy (B+1,INT_MAX);
    vector<int>sell (B+1,0);
    for(int i=0;i<n;i++)
    for(int j=1;j<=B;j++)
    {
        buy[j]=min(buy[j],A[i]-sell[j-1]);
        sell[j]=max(sell[j],A[i]-buy[j]);
    }
    
    return sell[B];
}