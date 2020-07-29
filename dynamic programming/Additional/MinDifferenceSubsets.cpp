// Given an integer array A containing N integers.

// You need to divide the array A into two subsets S1 and S2 such that the absolute difference between their sums is minimum.

// Find and return this minimum possible absolute difference.

// NOTE:

// Subsets can contain elements from A in any order (not necessary to be contiguous).
// Each element of A should belong to any one subset S1 or S2, not both.
// It may be possible that one subset remains empty.


// Problem Constraints
// 1 <= N <= 100

// 1 <= A[i] <= 100



// Input Format
// First and only argument is an integer array A.



// Output Format
// Return an integer denoting the minimum possible difference among the sums of two subsets.



// Example Input
// Input 1:

//  A = [1, 6, 11, 5]


// Example Output
// Output 1:

//  1


// Example Explanation
// Explanation 1:

//  Subset1 = {1, 5, 6}, sum of Subset1 = 12
//  Subset2 = {11}, sum of Subset2 = 11

#include <bits/stdc++.h>
using namespace std;

bool subsetsum(vector<int>A,int sum,int &maxValue){ //maxValue stores the max sum possible within range/2
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
    //storing the possible values less than range/2 ao as to not generate repetitve combinations
    maxValue=INT32_MIN;
    for(int i=1;i<=sum/2;i++){
        if(t[A.size()][i]){
            maxValue=max(maxValue,i);
        }
    }
    return t[A.size()][sum];
}

int minSubsetDiff(vector<int>A){
    int range=0;
    for(int i=0;i<A.size();i++){
        range+=A[i];
    }
    int Maxvalue;
    subsetsum(A,range,Maxvalue);
    // cout<<Maxvalue<<endl;
    return range-2*Maxvalue;
}
int solve(vector<int> &A) {
    return minSubsetDiff(A);
}
