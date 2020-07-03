// Problem Description

// Say you have an array, A, for which the ith element is the price of a given stock on day i.
// If you were only permitted to complete at most one transaction (i.e, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

// Return the maximum possible profit.



// Problem Constraints
// 0 <= len(A) <= 7e5

// 1 <= A[i] <= 1e7



// Input Format
// The first and the only argument is an array of integers, A.



// Output Format
// Return an integer, representing the maximum possible profit.



// Example Input
// Input 1:

//  A = [1, 2]
// Input 2:

//  A = [1, 4, 5, 2, 4]


// Example Output
// Output 1:
//  1
// Output 2:

//  4


// Example Explanation
// Explanation 1:

//  Buy the stock on day 0, and sell it on day 1.
// Explanation 2:

//  Buy the stock on day 0, and sell it on day 2.

#include<iostream>
#include<vector>
using namespace std;
//best solution
int maxProfit(const vector<int> &A) {
    int result=0;
    int minn=A[0];
    if(A.size()==0) return result;
    for(int i=0;i<A.size();i++){
        if(A[i]<minn){
            minn=A[i];
        }
        result=max(result,A[i]-minn);
    }
    return result;
}

//using dp but O(n square)
int maxProfit_1(const vector<int> &A) {
    vector<int>temp(A.size(),0);
    for(int i=0;i<A.size();i++){
        for(int j=0;j<i;j++){
            if(A[j]<A[i]){
                temp[i]=max(temp[i],A[i]-A[j]);
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
    vector<int>A = {1, 4, 5, 2, 4};
    cout<<maxProfit(A)<<endl;
    cout<<maxProfit_1(A);
}