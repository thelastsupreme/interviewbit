// Problem Description

// Given a string A, find length of the longest repeating sub-sequence such that the two subsequence don’t have same string character at same position,

// i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

// NOTE: Sub-sequence length should be greater than or equal to 2.



// Problem Constraints
// 1 <= |A| <= 100



// Input Format
// The first and the only argument of input contains a string A.



// Output Format
// Return an integer, 0 or 1:

//     => 0 : False
//     => 1 : True


// Example Input
// Input 1:

//  A = "abab"
// Input 2:

//  A = "abba"


// Example Output
// Output 1:

//  1
// Output 2:

//  0


// Example Explanation
// Explanation 1:

//  "ab" is repeated.
// Explanation 2:

//  There is no repeating subsequence.
#include <bits/stdc++.h>
using namespace std;


int anytwo(string a) {
    vector<vector<int>>temp(a.size()+1,vector<int>(a.size()+1,0));
    int match;
    for (int i = 1; i <a.size()+1; i++){
        for(int j=1;j<a.size()+1;j++){
            match=(a[i-1]==a[j-1]&&i!=j)?1:0;        //i!=j is the most important condition
            int x=max(temp[i-1][j],temp[i][j-1]);
            temp[i][j]=max(temp[i-1][j-1]+match,x);
        }
    }
    if(temp[a.size()][a.size()]>=2)   //cause question said >2
        return 1;
    else
        return 0;
}
