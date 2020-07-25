// Problem Description

// You are given a preorder traversal A, of a Binary Search Tree.

// Find if it is a valid preorder traversal of a BST.



// Problem Constraints
// 1 <= A[i] <= 106

// 1 <= |A| <= 105



// Input Format
// First and only argument is an integer array A denoting the pre-order traversal.



// Output Format
// Return an integer:

// 0 : Impossible preorder traversal of a BST
// 1 : Possible preorder traversal of a BST


// Example Input
// Input 1:

// A = [7, 7, 10, 10, 9, 5, 2, 8]


// Example Output
// Output 1:

//  1

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Editorial recursive
int solve(vector<int> &A) 
{
    int n = A.size();
    if(n==1 || n==0) return true;
    int root = A[0];
    vector <int> left;
    vector <int> right;
    int st = 1;
    while(st<n && A[st]<=root)
    {
        left.push_back(A[st]);
        st++;
    }
    while(st<n && A[st]>root)
    {
        right.push_back(A[st]);
        st++;
    }
    if(st!=n) return 0;
    int r1 = solve(left);
    int r2 = solve(right);
    return r1&r2;
}

//iterative using stacks
int solve_1(vector<int> &pre) {
    stack<int> s;
    int root = INT_MIN;
    
    for(int i =0;i<pre.size();i++){
        if(root > pre[i]){
            return 0;
        }
        while(!s.empty() && s.top()<pre[i]){
           root = s.top();
           s.pop();
        }
        s.push(pre[i]);
    }
    return 1;
}

int main()
{
    vector<int>A={5,3,2,4,7,6,8};
    cout<<solve(A);
    cout<<solve_1(A);
}