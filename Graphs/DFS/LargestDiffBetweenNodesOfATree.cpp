// Given an arbitrary unweighted rooted tree which consists of N nodes.

// The goal of the problem is to find largest distance between two nodes in a tree.

// Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree).

// The nodes will be numbered 0 through N - 1.

// The tree is given as an array A, there is an edge between nodes A[i] and i (0 <= i < N). Exactly one of the i's will have A[i] equal to -1, it will be root node.



// Problem Constraints
// 1 <= N <= 40000



// Input Format
// First and only argument is an integer array A of size N.



// Output Format
// Return a single integer denoting the largest distance between two nodes in a tree.



// Example Input
// Input 1:

//  A = [-1, 0, 0, 0, 3]


// Example Output
// Output 1:

//  3


// Example Explanation
// Explanation 1:

//  node 0 is the root and the whole tree looks like this: 
//           0
//        /  |  \
//       1   2   3
//                \
//                 4

//  One of the longest path is 1 -> 0 -> 3 -> 4 and its length is 3, thus the answer is 3.

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int> adj[], int root, int &ans)
{
    if (adj[root].size() == 0)  //if leaf node return empty
        return 1;
    int max1 = 0, max2 = 0;
    for (int i = 0; i < adj[root].size(); i++)
    {
        int h = dfs(adj, adj[root][i], ans); 
        if (h > max1)
        {
            max2 = max1;
            max1 = h;
        }
        else if (h > max2)
        {
            max2 = h;
        }
    }
    ans = max(ans, max1 + max2 + 1);  //just like with trees there are two possiblities either a subtree with two max subpaths has max length
                                      //or not, refer diameter of trees for further clarity
    return max(max1, max2) + 1;
}

int solve(vector<int> &A)
{
    int n = A.size();
    vector<int> adj[n + 1]; //2d adjacency matrix
    int root;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == -1)
        {
            root = i;
            continue;
        }
        else
        {
            adj[A[i]].push_back(i); //construct
        }
    }
    int ans = 0;
    if (adj[root].size() == 0)  //if root doesnt have any nodes connected end
        return 0;
    dfs(adj, root, ans);
    return ans - 1;
}

//FASTEST
int solve_fastest(vector<int> &A) {
     vector<int> hgt(A.size(),0);
    int ans=0,maxx=0;
    for(int i=A.size()-1;i>0;i--){
        ans=max(ans,hgt[A[i]]+hgt[i]+1);
        hgt[A[i]]=max(hgt[i]+1,hgt[A[i]]);
    }
    return ans;
}