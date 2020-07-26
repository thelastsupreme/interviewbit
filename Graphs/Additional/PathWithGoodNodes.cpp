// Problem Description

// Given a tree with N nodes labelled from 1 to N.

// Each node is either good or bad denoted by binary array A of size N where if A[i] is 1 then ithnode is good else if A[i] is 0 then ith node is bad.

// Also the given tree is rooted at node 1 and you need to tell the number of root to leaf paths in the tree that contain not more than C good nodes.

// NOTE:

// Each edge in the tree is bi-directional.


// Problem Constraints
// 2 <= N <= 105

// A[i] = 0 or A[i] = 1

// 0 <= C <= N



// Input Format
// First argument is an binary integer array A of size N.

// Second argument is a 2-D array B of size (N-1) x 2 denoting the edge of the tree.

// Third argument is an integer C.



// Output Format
// Return an integer denoting the number of root to leaf paths in the tree that contain not more than C good nodes.



// Example Input
// Input 1:

//  A = [0, 1, 0, 1, 1, 1]
//  B = [  [1, 2]
//         [1, 5]
//         [1, 6]
//         [2, 3]
//         [2, 4]
//      ]
//  C = 1


// Example Output
// Output 1:

//  3


// Example Explanation
// Explanation 1:

//  Path (1 - 2 - 3) and (1 - 5) and (1 - 6) are the paths which contain atmost C nodes.
#include <bits/stdc++.h>
using namespace std;



void dfs(int root,vector<int> adj[],int goodnodes,vector<int> &A,int limit,int &ans)
{
    if(A[root-1]) goodnodes++; //if good
    if(adj[root].size()==0)  //if no adj edges then its a leaf
    {
        if(goodnodes<=limit) ans++;
        return ;
    }
    for(auto x : adj[root]) //dfs for all adj nodes
        dfs(x,adj,goodnodes,A,limit,ans);
}
int solve(vector<int> &A, vector<vector<int> > &B, int C) {
    vector<int> adj[A.size()+1];
    for(auto x : B) 
    (x[0]<x[1])?adj[x[0]].push_back(x[1]):adj[x[1]].push_back(x[0]); //making sure smaller number is connected with bigger one
    int ans=0;
    dfs(1,adj,0,A,C,ans);
    return ans;
}

int main()
{

}