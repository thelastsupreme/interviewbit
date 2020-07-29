// Say you have an array, A, for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most 2 transactions.

// Return the maximum possible profit.

// Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


// Input Format:

// The first and the only argument is an integer array, A.
// Output Format:

// Return an integer, representing the maximum possible profit.
// Constraints:

// 1 <= length(A) <= 7e5
// 1 <= A[i] <= 1e7
// Examples:

// Input 1:
//     A = [1, 2, 1, 2]

// Output 1:
//     2

// Explanation 1: 
//     Day 0 : Buy 
//     Day 1 : Sell
//     Day 2 : Buy
//     Day 3 : Sell

// Input 2:
//     A = [7, 2, 4, 8, 7]

// Output 2:
//     6

// Explanation 2:
//     Day 1 : Buy
//     Day 3 : Sell


#include <bits/stdc++.h>
using namespace std;

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
int maxProfit(const vector<int> &A) {
    vector<int>temp=A;
    return solve_editorial(temp,2); //used stocks B times and called it for 2
}
