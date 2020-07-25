// Problem Description

// Given a undirected tree with N nodes labeled from 1 to N.

// Each node has a certain weight assigned to it given by an integer array A of size N.

// You need to delete an edge in such a way that Product between sum of weight of nodes in one subtree with sum of weight of nodes in other subtree is maximized.

// Return this maximum possible product modulo 109 + 7.

// NOTE:

// The tree is rooted at node labeled with 1.


// Problem Constraints
// 2 <= N <= 105

// 1 <= A[i] <= 103



// Input Format
// First argument is an integer array A of size N denoting the weight of each node.

// Second argument is a 2-D array B of size (N-1) x 2 denoting the edge of the tree.



// Output Format
// Return a single integer denoting the maximum product prossible of sum of weights of nodes in the two subtrees formed by deleting an edge with modulo 109 + 7.



// Example Input
// Input 1:

//  A = [10, 5, 12, 6]
//  B = [

//         [1, 2]
//         [1, 4]
//         [4, 3]
//      ]
// Input 2:

//  A = [11, 12]
//  B = [

//         [1, 2]
//      ]


// Example Output
// Output 1:

//  270
// Output 2:

//  132


// Example Explanation
// Explanation 1:

//  Removing edge (1, 4) created two subtrees.
//  Subtree-1 contains nodes (1, 2) and Subtree-2 contains nodes (3, 4)
//  So product will be = (A[1] + A[2]) * (A[3] + A[4]) = 15 * 18 = 270
// Explanation 2:

//  Removing edge (1, 2) created two subtrees.
//  Subtree-1 contains node (1) and Subtree-2 contains node (3)
//  So product will be = (A[1]) * (A[2]) = 11 * 12 = 132
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100009;
vector < int > adj[maxn];
long long s;
long long maxe;
const int mod = 1e9 + 7;

//fastest solution
//basic idea is keep dfsing then at some point sum of prodcut of nodes u visted
//and sum of product of nodes u didnt visit will be max
//so just store that max value
int dfs(int u, int p, vector < int > & A) {
  long long sum = A[u - 1];
  for (int v: adj[u]) {
    if (v == p) continue;
    sum += dfs(v, u, A);
  }
  long long res = ((sum % mod) * ((s - sum) % mod)) % mod;
  maxe = max(maxe, res);
  return sum;
}

int deleteEdge(vector < int > & A, vector < vector < int > > & B) 
{

  s = 0; //total sum of tree
  maxe = 0; //maximum product

  //clearing the adjacency list
  for (int i = 0; i <= A.size(); i++)
    adj[i].clear();

  //Calculating sum of weights of all nodes
  for (int a: A)
    s += a;

  //Creating tree 
  for (auto & it: B) {
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
  }

  dfs(1, 0, A);

  return maxe;
}

int main()
{

}