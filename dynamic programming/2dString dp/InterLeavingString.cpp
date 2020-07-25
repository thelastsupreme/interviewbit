// Given A, B, C, find whether C is formed by the interleaving of A and B.

// Input Format:*

// The first argument of input contains a string, A.
// The second argument of input contains a string, B.
// The third argument of input contains a string, C.
// Output Format:

// Return an integer, 0 or 1:
//     => 0 : False
//     => 1 : True
// Constraints:

// 1 <= length(A), length(B), length(C) <= 150
// Examples:

// Input 1:
//     A = "aabcc"
//     B = "dbbca"
//     C = "aadbbcbcac"

// Output 1:
//     1
    
// Explanation 1:
//     "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

// Input 2:
//     A = "aabcc"
//     B = "dbbca"
//     C = "aadbbbaccc"

// Output 2:
//     0

// Explanation 2:
//     It is not possible to get C by interleaving A and B.
#include <bits/stdc++.h>
using namespace std;

//used print LCS function
string LCS(string A,string B){
    vector<vector<int>>t(A.size()+1,vector<int>(B.size()+1,0));

    //generate LCS t Matrix
    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<B.size()+1;j++){
            if(A[i-1]==B[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
            
        }
    }
    //now iterate from the back and at a location check
    //if the char at that row index in A and char at that column index at B are equal
    //if yes then add them to result string
    //else go for the next location either top or left whichever has more value
    int i=A.size(),j=B.size();
    string res="";
    while (i>0&&j>0){
        if(A[i-1]==B[j-1]){
            res+=A[i-1];
            i--;                 
            j--;
        }else{
            if(t[i-1][j]>t[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(res.begin(),res.end());
    return res;
    
}
int isInterleave(string A, string B, string C) {
    if(LCS(A,C)==A &&LCS(B,C)==B)
        return 1;
    return 0;
}

