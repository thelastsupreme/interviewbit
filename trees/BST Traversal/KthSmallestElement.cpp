// Given a binary search tree, write a function to find the kth smallest element in the tree.

// Example :

// Input : 
//   2
//  / \
// 1   3

// and k = 2

// Return : 2

// As 2 is the second smallest element in the tree.
//  NOTE : You may assume 1 <= k <= Total number of nodes in BST 


#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* A,vector<int>&traversal){
    if(A==NULL){
        return;
    }
    else{
        traversal.push_back(A->val);
        helper(A->left,traversal);
        helper(A->right,traversal);
    }
}

int kthsmallest(TreeNode* A, int B) {
    vector<int>traversal;
    traversal.clear();
    helper(A,traversal);
    sort(traversal.begin(),traversal.end());
    return traversal[B-1];
}

int main()
{
    
}