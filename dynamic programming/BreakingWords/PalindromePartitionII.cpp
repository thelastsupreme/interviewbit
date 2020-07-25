// Given a string A, partition A such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of A.



// Input Format:

// The first and the only argument contains the string A.
// Output Format:

// Return an integer, representing the answer as described in the problem statement.
// Constraints:

// 1 <= length(A) <= 501
// Examples:

// Input 1:
//     A = "aba"

// Output 1:
//     0

// Explanation 1:
//     "aba" is already a palindrome, so no cuts are needed.

// Input 2:
//     A = "aab"
    
// Output 2:
//     1

// Explanation 2:
//     Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 50
vector<vector<int>>t(MAXSIZE,vector<int>(MAXSIZE,-1));

bool isPalindrome(string A,int i,int j){
    string T(A,i,j-i+1);
    string B=T;
    reverse(B.begin(),B.end());
    return(T==B);
}

//this question needs optimization beyond just using a global mem matrix
int PalindromePart(string &A,int i,int j){
    if(i>=j)
        return 0;
    if(isPalindrome(A,i,j))
        return 0;
    int res=INT32_MAX;
    //********code before optimization*****************
    // for(int k=i;k<=j-1;k++){
    //     int tempans=PalindromePart(A,i,k)+PalindromePart(A,k+1,j)+1; //+1 cause we just made a partition
    //     res=min(res,tempans);
    // }
    if(t[i][i]!=-1)
        return t[i][j];
    for(int k=i;k<=j-1;k++){
        int left=0,right=0;
        //the below if else ladder helps in further optimization
        //for parts of the recursive calls
        if(t[i][k]!=-1){
            left=t[i][k];
        }else{
            left=PalindromePart(A,i,k);
        }

        if(t[k+1][j]!=-1){
            right=t[k+1][j];
        }else{
            right=PalindromePart(A,k+1,j);
        }
        int tempans=left+right+1; //+1 cause we just made a partition
        res=min(res,tempans);
    }

    return t[i][j]=res;  //store in mem matrix
}

int main(){
    string s="nitik"; //op 2
    cout<<PalindromePart(s,0,s.size()-1);
}
