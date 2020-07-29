// Find longest Arithmetic Progression in an integer array A of size N, and return its length.

// More formally, find longest sequence of indices, 0 < i1 < i2 < … < ik < ArraySize(0-indexed) such that sequence A[i1], A[i2], …, A[ik] is an Arithmetic Progression.

// Arithmetic Progression is a sequence in which all the differences between consecutive pairs are the same, i.e sequence B[0], B[1], B[2], …, B[m - 1] of length m is an Arithmetic Progression if and only if B[1] - B[0] == B[2] - B[1] == B[3] - B[2] == … == B[m - 1] - B[m - 2]

// Note: The common difference can be positive, negative or 0.



// Input Format:

// The first and the only argument of input contains an integer array, A.
// Output Format:

// Return an integer, representing the length of the longest possible arithmetic progression.
// Constraints:

// 1 <= N <= 1000
// 1 <= A[i] <= 1e9
// Examples:

// Input 1:
//     A = [3, 6, 9, 12]

// Output 1:
//     4

// Explanation 1:
//     [3, 6, 9, 12] form an arithmetic progression.

// Input 2:
//     A = [9, 4, 7, 2, 10]

// Output 2:
//     3

// Explanation 2:
//     [4, 7, 10] form an arithmetic progression.
#include <bits/stdc++.h>
using namespace std;

//editorial soln
int solve(const vector<int> &A)
{
    int n = A.size();
    if (n < 3)
        return n;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    map<int, int> pos;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            dp[i][j] = 2;
            int dif = A[j] - A[i];
            int need = 2 * A[i] - A[j];
            if (pos.count(need) == 0)
                continue;
            dp[i][j] = max(dp[i][j], dp[pos[need]][i] + 1);
        }
        pos[A[i]] = i;
    }
    int ans = 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}