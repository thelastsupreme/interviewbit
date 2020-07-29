// Two kingdoms are on a war right now, kingdom X and kingdom Y. As a war specialist of kingdom X, you scouted kingdom Y area.

// A kingdom area is defined as a N x M grid with each cell denoting a village.
// Each cell has a value which denotes the strength of each corresponding village.
// The strength can also be negative, representing those warriors of your kingdom who were held hostages.

// There’s also another thing to be noticed.

// The strength of any village on row larger than one (2<=r<=N) is stronger or equal to the strength of village which is exactly above it.
// The strength of any village on column larger than one (2<=c<=M) is stronger or equal to the strength of vilage which is exactly to its left.
// (stronger means having higher value as defined above).
// So your task is, find the largest sum of strength that you can erase by bombing one sub-matrix in the grid.

// Input format:

// First line consists of 2 integers N and M denoting the number of rows and columns in the grid respectively.
// The next N lines, consists of M integers each denoting the strength of each cell.

// 1 <= N <= 1500
// 1 <= M <= 1500
// -200 <= Cell Strength <= 200
// Output:

// The largest sum of strength that you can get by choosing one sub-matrix.
// Example:

// Input:
// 3 3
// -5 -4 -1
// -3 2 4
// 2 5 8

// Output:
// 19

// Explanation:
// Bomb the sub-matrix from (2,2) to (3,3): 2 + 4 + 5 + 8 = 19

#include<iostream>
#include<vector>
using namespace std;

int solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    
    vector<int> temp(m, 0);
    int maxs = 0, tmp = A[0][0];
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = 0; j < m; j++)
           temp[j] += A[i][j], tmp = max(tmp, A[i][j]); //storing column sum in single 1d vector
           //and a single largest element          
        int tmps = 0;
        for(int j = m-1; j >= 0 && temp[j] > 0; j--)
            tmps += temp[j]; //now check whats the max op i can generate
        maxs = max(maxs, tmps);
    }
    if(maxs == 0) //if it remains 0 return that one single element
        maxs = tmp;
    return maxs;
}

int main(){
    vector<vector<int>>A={{-5,-4,-1},{-3,2,4},{2,5,8}};
    cout<<solve(A);
}