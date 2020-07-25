// You are given a set of coins S. In how many ways can you make sum N assuming you have infinite amount of each coin in the set.

// Note : Coins in set S will be unique. Expected space complexity of this problem is O(N).

// Example :

// Input : 
// 	S = [1, 2, 3] 
// 	N = 4

// Return : 4

// Explanation : The 4 possible ways are
// {1, 1, 1, 1}
// {1, 1, 2}
// {2, 2}
// {1, 3}	
// Note that the answer can overflow. So, give us the answer % 1000007
#include <bits/stdc++.h>
using namespace std;

// O(N^2) memory needed
// int coinChange(vector<int>denominations,int value){
//     vector<vector<int>>t(denominations.size()+1,vector<int>(value+1,0));

//     for(int i=1;i<denominations.size()+1;i++){
//         t[i][0]=1; //cause if u dont select any coins you can have a sum of 0
//     }
//     for(int i=1;i<denominations.size()+1;i++){
//         for(int j=1;j<value+1;j++){
//             if(denominations[i-1]<=j){
//                 t[i][j]=t[i][j-denominations[i-1]]+t[i-1][j]; //just add all possible ways
//             }
//             else{
//                 t[i][j]=t[i-1][j];
//             }
            
//         }
//     }
//     return t[denominations.size()][value];
// }

//in O(N) memory
#define m 1000007
void print(vector<int>A)
{
    for (int i = 0; i <A.size(); i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int coinchange2(vector<int> &A, int B) {
    int n = A.size();
    vector<int> dp(B+1, 0);
    dp[0]=1;
    
    for(int i=1; i<=n; i++){
        for(int j=A[i-1]; j<=B; j++)
        {
            dp[j] += dp[j-A[i-1]]%m;
            print(dp);
        }
    }
    
    return dp[B]%m;
}

int main(){
    vector<int>denoms={25,10,5,1};
    cout<<coinchange2(denoms,10)<<endl;
}