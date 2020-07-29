// Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

// Now consider if some obstacles are added to the grids. How many unique paths would there be?
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// Example :
// There is one obstacle in the middle of a 3x3 grid as illustrated below.

// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &A) {
    vector<vector<int>>temp(A.size(),vector<int>(A[0].size(),0));
    
    for(int i=0;i<temp.size();i++){
        if(A[i][0]==1) break;
            
        temp[i][0]=1;
    }
    for(int j=0;j<temp[0].size();j++){
        if(A[0][j]==1) break;
            
        temp[0][j]=1;
    }
    
    for(int i=1;i<A.size();i++){
        for(int j=1;j<A[0].size();j++){
            if(A[i][j]!=1){
                temp[i][j]=temp[i-1][j]+temp[i][j-1];
            }
        }
    }
    return temp[A.size()-1][A[0].size()-1];
}

int main(){
    vector<vector<int>>A = {{0, 0, 0},{0, 1, 0},{0, 0, 0}};
    cout<<uniquePathsWithObstacles(A);
}