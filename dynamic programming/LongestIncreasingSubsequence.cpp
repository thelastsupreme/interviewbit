// Find the longest increasing subsequence of a given array of integers, A.

// In other words, find a subsequence of array in which the subsequence’s elements are in strictly increasing order, and in which the subsequence is as long as possible.
// This subsequence is not necessarily contiguous, or unique.
// In this case, we only care about the length of the longest increasing subsequence.


// Input Format:

// The first and the only argument is an integer array A.
// Output Format:

// Return an integer representing the length of the longest increasing subsequence.
// Constraints:

// 1 <= length(A) <= 2500
// 1 <= A[i] <= 2000
// Example :

// Input 1:
//     A = [1, 2, 1, 5]

// Output 1:
//     3
    
// Explanation 1:
//     The sequence : [1, 2, 5]

// Input 2:
//     A = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
    
// Output 2:
//     6

// Explanation 2:
//     The sequence : [0, 2, 6, 9, 13, 15] or [0, 4, 6, 9, 11, 15] or [0, 4, 6, 9, 13, 15]

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lis(const vector<int> &A) {
    vector<int>temp(A.size(),1);
    for(int i=0;i<temp.size();i++){
        for(int j=0;j<i;j++){
            if(A[j]<A[i]&&temp[j]+1>temp[i]){
                temp[i]=temp[j]+1;
            }
        }
    }
    int result=0;
    for(int i=0;i<temp.size();i++){
        result=max(result,temp[i]);
    }
    return result;
}

int main(){
    vector<int>A={7,2,1,3,8,4,9,1,2,6,5,9,3,8,1};
    cout<<lis(A);
}