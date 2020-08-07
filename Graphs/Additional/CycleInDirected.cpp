// Problem Description

// Given an directed graph having A nodes. A matrix B of size M x 2 is given which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].

// Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

// NOTE:

// The cycle must contain atleast two nodes.
// There are no self-loops in the graph.
// There are no multiple edges between two nodes.
// The graph may or may not be connected.
// Nodes are numbered from 1 to A.
// Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


// Problem Constraints
// 2 <= A <= 105

// 1 <= M <= min(200000,A(A-1))

// 1 <= B[i][0], B[i][1] <= A



// Input Format
// The first argument given is an integer A representing the number of nodes in the graph.

// The second argument given a matrix B of size M x 2 which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].



// Output Format
// Return 1 if cycle is present else return 0.



// Example Input
// Input 1:

//  A = 5
//  B = [  [1, 2] 
//         [4, 1] 
//         [2, 4] 
//         [3, 4] 
//         [5, 2] 
//         [1, 3] ]
// Input 2:

//  A = 5
//  B = [  [1, 2]
//         [2, 3] 
//         [3, 4] 
//         [4, 5] ]


// Example Output
// Output 1:

//  1
// Output 2:

//  0


// Example Explanation*
// Explanation 1:

//  The given graph contain cycle 1 -> 3 -> 4 -> 1 or the cycle 1 -> 2 -> 4 -> 1
// Explanation 2:

//  The given graph doesn't contain any cycle.
#include <bits/stdc++.h>
using namespace std;


void print(vector<int>A)
{
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

// int findd(vector<int>&parent,int i)  //basically checks if your nodes on dfs traversing end at same nodes
// {
//     if(parent[i]==i)
//         return i;
//     return parent[i]=findd(parent,parent[i]);
// }

// int solve(int A, vector<vector<int> > &B) {
//     vector<int>parent(A+1);
//     for(int i=0;i<parent.size();i++)
//         parent[i]=i;

//     for(int i=0;i<B.size();i++)
//     {
//         print(parent);
//         int u=B[i][0];
//         int v=B[i][1];
//         cout<<u<<" "<<v<<endl;
//         int set_u=findd(parent,u);
//         int set_v=findd(parent,v);
//         cout<<set_u<<" "<<set_v<<endl;
//         if(set_u==set_v)
//             return 1;
//         parent[u]=parent[v];
//     }
//     return 0;
// }

// method 3 using dfs
bool dfs(int s,vector<bool> &visited,vector<vector<int>> &B) {
    if (visited[s]) return true;
    visited[s] = true;
    // process node s
    for (int i=0;i<B.size();i++) {
        if(B[i][0]==s && dfs(B[i][1],visited,B))
            return true;
    }
    visited[s]=false;
    return false;
}

int solve(int A, vector<vector<int> > &B) {
    int E=B.size();
    for(int i=1;i<=A;i++){
        vector<bool> visited(A+1,false);
        // stack<int> dfs;
        if(dfs(i,visited,B)){
            return 1;
        }
    }
    return 0;
}

int main()
{
    vector<vector<int>> A = 
    {
        {1, 4},
        {2, 1},
        {4, 3},
        {4, 5},
        {2, 3},
        {2, 4},
        {1, 5},
        {5, 3},
        {2, 5},
        {5, 1},
        {4, 2},
        {3, 1},
        {5, 4},
        {3, 4},
        {1, 3},
        {4, 1},
        {3, 5},
        {3, 2},
        {5, 2}};

    cout << solve(5, A);
}