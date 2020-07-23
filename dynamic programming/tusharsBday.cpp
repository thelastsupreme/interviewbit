#include <bits/stdc++.h>
using namespace std;

int UnBoundedKnapsack(vector<int>weights,vector<int>values,int capacity){
    vector<vector<int>>t(weights.size()+1,vector<int>(capacity+1,0));

    for(int i=1;i<capacity+1;i++)
    {
        t[0][i]=50000;      //init is diff if u want min cost knapsack
    }
    for(int i=1;i<weights.size()+1;i++){
        for(int j=1;j<capacity+1;j++){
            if(weights[i-1]<=j){
                t[i][j]=min(values[i-1]+t[i][j-weights[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
            
        }
    }
    // for(int i=0;i<weights.size()+1;i++){
    //     for(int j=0;j<capacity+1;j++){
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return t[weights.size()][capacity];
}
int solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int cost=0;
    for(int i=0;i<A.size();i++){
        int x=UnBoundedKnapsack(B,C,A[i]);
        cost+=x;
        // cout<<x<<endl;
    }
    return cost;
}

int main(){
    vector<int>A ={ 2, 3, 1, 5, 4};
    vector<int>B={ 3, 2, 4, 1 };
    vector<int>C={1, 2,5,10};
    cout<<solve(A,B,C);
}