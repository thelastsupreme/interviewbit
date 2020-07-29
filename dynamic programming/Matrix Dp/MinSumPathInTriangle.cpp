// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

// For example, given the following triangle

// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

//  Note:
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 

#include<iostream>
#include<vector>
using namespace std;

int minimumTotal(vector<vector<int> > &A) {
    for(int i=1;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            if(j==0){
                A[i][j]+=A[i-1][j];
            }else if(j==A[i].size()-1){
                A[i][j]+=A[i-1][A[i-1].size()-1];
            }else{
                A[i][j]+=min(A[i-1][j],A[i-1][j-1]);
            }
        }
    }
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    int minn=INT32_MAX;
    for(int i=0;i<A[A.size()-1].size();i++){
        minn=min(minn,A[A.size()-1][i]);
    }
    return minn;
}

int main(){
    vector<vector<int>>A={{9},{3,8},{0,2,4},{8,3,9,0},{5,2,2,7,3},{7,9,0,2,3,9},{9,7,0,3,9,8,6},{ 5,7,6,2,7,0,3,9}};
    cout<<minimumTotal(A);
}