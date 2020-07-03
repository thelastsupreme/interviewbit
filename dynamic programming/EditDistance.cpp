// Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

// You have the following 3 operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character


// Input Format:

// The first argument of input contains a string, A.
// The second argument of input contains a string, B.
// Output Format:

// Return an integer, representing the minimum number of steps required.
// Constraints:

// 1 <= length(A), length(B) <= 450
// Examples:

// Input 1:
//     A = "abad"
//     B = "abac"

// Output 1:
//     1

// Explanation 1:
//     Operation 1: Replace d with c.

// Input 2:
//     A = "Anshuman"
//     B = "Antihuman"

// Output 2:
//     2

// Explanation 2:
//     => Operation 1: Replace s with t.
//     => Operation 2: Insert i.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int editDistance(string a ,string b){
    vector<vector<int>>temp(a.size()+1,vector<int>(b.size()+1,0));
    for(int i=0;i<a.size()+1;i++){
        temp[i][0]=i;
    }
    for(int j=0;j<b.size()+1;j++){
        temp[0][j]=j;
    }
    int diff;
    for (int i = 1; i <a.size()+1; i++){
        for(int j=1;j<b.size()+1;j++){
            diff=(a[i-1]==b[j-1])?0:1;
            int x=min(temp[i-1][j]+1,temp[i][j-1]+1);
            temp[i][j]=min(x,temp[i-1][j-1]+diff);
        }
    }

    return temp[a.size()][b.size()];
}

int main(){
    int k=editDistance("aac","abac");
    cout<<"Cost is : "<<k;
}