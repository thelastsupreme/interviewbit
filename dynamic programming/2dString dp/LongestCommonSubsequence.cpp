// Problem Description

// Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings.

// You need to return the length of such longest common subsequence.

// Problem Constraints
// 1 <= |A|, |B| <= 1005
// Input Format
// First argument is an string A.

// Second argument is an string B.

// Output Format
// Return the length of such longest common subsequence between string A and string B.

// Example Input
// Input 1:

//  A = "abbcdgf"
//  B = "bbadcgf"

// Example Output
// Output 1:
//  5
// Example Explanation
// Explanation 1:
//  The longest common subsequence is "bbcgf", which has a length of 5

#include<iostream>
#include<string>
#include<vector>
using namespace std;


//core logic check match then if match take max of all possible combinations
//like remove one element from A and check again with B vice versa
int lcs(string a,string b){
    vector<vector<int>>temp(b.size()+1,vector<int>(a.size()+1,0));
    int match;
    for (int i = 1; i <b.size()+1; i++){
        for(int j=1;j<a.size()+1;j++){
            match=(a[i-1]==b[j-1])?1:0;
            int x=max(temp[i-1][j],temp[i][j-1]);
            temp[i][j]=max(temp[i-1][j-1]+match,x);
        }
    }
    return temp[b.size()][a.size()];
}
int main(){
    int k=lcs("abbcdgf","bbadcgf");
    cout<<"Cost is : "<<k;
}