// Implement regular expression matching with support for '.' and '*'.

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.

// The matching should cover the entire input string (not partial).

// The function prototype should be:

// int isMatch(const char *s, const char *p)
// Some examples:

// isMatch("aa","a") → 0
// isMatch("aa","aa") → 1
// isMatch("aaa","aa") → 0
// isMatch("aa", "a*") → 1
// isMatch("aa", ".*") → 1
// isMatch("ab", ".*") → 1
// isMatch("aab", "c*a*b") → 1
// Return 0 / 1 ( 0 for false, 1 for true ) for this problem
#include <bits/stdc++.h>
using namespace std;

int isMatch(const string A, const string B) {
    vector<vector<bool>>t(A.size()+1,vector<bool>(B.size()+1,false));
    
    t[0][0]=true;
    
    for (int j = 1; j <B.size()+1 && B[j] == '*'; j += 2)
    {
        t[0][j] = true;
        t[0][j+1] = true;
    }

    
    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<B.size()+1;j++){
            if(A[i-1]==B[j-1]||B[j-1]=='.')
                t[i][j]=t[i-1][j-1];

            if(j!=1&&B[j-1]=='*'){       
                 t[i][j] = (t[i][j - 2]) ||(t[i - 1][j] && (A[i - 1] == B[j - 2] || B[j - 2] == '.'));
            }
        }
    }
    return(t[A.size()][B.size()]);
}

int main()
{
    
}