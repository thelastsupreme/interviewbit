// You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
// f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

// For example,

// A=[1, 3, -1]

// f(1, 1) = f(2, 2) = f(3, 3) = 0
// f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
// f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
// f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

// So, we return 5.

#include<iostream>
#include<vector>
using namespace std;

//logic: remember on opening a mod u always get two values so open the expression up and just try to frame two eqs
int maxArr(vector<int>A) {
    //variables to store max and min of both eqs
    int best=0,max_feq=INT32_MIN,max_seq=INT32_MIN,min_feq=INT32_MAX,min_seq=INT32_MAX;
    for(int i=0;i<A.size();i++)
        {
            max_feq=max(max_feq,A[i]+i); //first eq =(A[i]+i)-(A[j]+j)
            min_feq=min(min_feq,A[i]+i);

            max_seq=max(max_seq,A[i]-i); //second eq =(A[i]-i)-(A[j]-j)
            min_seq=min(min_seq,A[i]-i);

        }
    best=max(max_feq-min_feq,max_seq-min_seq); //just find the max of both eqs and done
    return best;
}

int main(){
    vector<int>A={1,3,-1};
    cout<<maxArr(A);
}