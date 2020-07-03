// Problem Description

// Given a string A, find the common palindromic sequence ( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself.

// You need to return the length of longest palindromic subsequence in A.

// NOTE:

// Your code will be run on multiple test cases (<=10). Try to come up with an optimised solution.

// Problem Constraints
// 1 <= |A| <= 1005

// Input Format
// First and only argument is an string A.

// Output Format
// Return a integer denoting the length of longest palindromic subsequence in A.

// Example Input
// Input 1 :
//  A = "bebeeed"
// Example Output
// Output 1:
//  4
// Example Explanation
// Explanation 1:

//  The longest common pallindromic subsequence is "eeee", which has a length of 4

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//logic just call lcs function on itself and its reverse
int lcs(string a, string b) {
    vector<vector<int>>temp(b.size()+1,vector<int>(a.size()+1,0));
    int match;
    for (int i = 1; i <b.size()+1; i++){
        for(int j=1;j<a.size()+1;j++){
            if(a[i-1]==b[j-1]){
                match=1;  
            }else{
                match=0;  
            }
            int x=max(temp[i-1][j],temp[i][j-1]);
            temp[i][j]=max(temp[i-1][j-1]+match,x);
        }
    }
    return temp[b.size()][a.size()];
}

int lpcs(string A) {
    string B=A;
    reverse(B.begin(),B.end());
    return lcs(A,B);
}

int main(){
    cout<<lpcs("bebeeed");
}