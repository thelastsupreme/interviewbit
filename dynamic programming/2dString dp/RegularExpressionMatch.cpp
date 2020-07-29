// Implement wildcard pattern matching with support for ‘?’ and ‘*’ for strings A and B.

// 1.’?’ : Matches any single character.
// 2.‘*’ : Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Input Format:

// The first argument of input contains a string A.
// The second argument of input contains a string B.
// Output Format:

// Return 0 or 1:
//     => 0 : If the patterns do not match.
//     => 1 : If the patterns match.
// Constraints:

// 1 <= length(A), length(B) <= 9e4
// Examples :

// Input 1:
//     A = "aa"
//     B = "a"

// Output 1:
//     0

// Input 2:
//     A = "aa"
//     B = "aa"

// Output 2:
//     1

// Input 3:
//     A = "aaa"
//     B = "aa"

// Output 3:
//     0
    
// Input 4:
//     A = "aa"
//     B = "*"

// Output 4:
//     1

// Input 5:
//     A = "aa"
//     B = "a*"

// Output 5:
//     1

// Input 6:
//     A = "ab"
//     B = "?*"

// Output 6:
//     1

// Input 7:
//     A = "aab"
//     B = "c*a*b"

// Output 7:
//     0

#include<iostream>
#include<vector>
using namespace std;

int isMatch(const string A, const string B) {
    vector<vector<bool>>t(A.size()+1,vector<bool>(B.size()+1,false));
    
    t[0][0]=true;
    
    for(int i=1;i<B.size()+1;i++){
        if(B[i-1]=='*'){
            t[0][i]=t[0][i-1];
        }
    }
    
    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<B.size()+1;j++){
            if(A[i-1]==B[j-1]||B[j-1]=='?')
                t[i][j]=t[i-1][j-1];

            if(B[j-1]=='*'){       
            //most important step
            //1.check by decrementing the star and next values of B with A
            //2.check by decrementing index of A and with same B ...
            //if u keep choosing second choice on every step eventually A will become empty and return false
                t[i][j]=t[i-1][j]||t[i][j-1];
            }
        }
    }
    return(t[A.size()][B.size()]);
}