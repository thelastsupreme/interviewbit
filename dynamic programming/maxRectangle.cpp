#include<iostream>
#include<vector>
using namespace std;

int maximalRectangle(vector<vector<int> > &A) {
    vector<vector<int>>temp(A.size()+1,vector<int>(A[0].size()+1,0));
    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<A[0].size();j++){
           temp[i][j]=A[i-1][j-1];
        }
    }
    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<A[0].size()+1;j++){
            if(A[i-1][j-1]==0) temp[i][j]=0;
            else{
                temp[i][j]=max(temp[i-1][j],temp[i][j-1])+1;
            }
        }
    }
    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<A[0].size();j++){
            if(temp[i][j]%10==temp[i][j]) cout<<" ";
           cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
    int result=0;
    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<A[0].size();j++){
           result=max(result,temp[i][j]);
        }
    }
    return result;
}

int main(){
    vector<vector<int>>A = 
{
  {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
  {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
  {1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0},
  {1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1}
};
    cout<<maximalRectangle(A);
}