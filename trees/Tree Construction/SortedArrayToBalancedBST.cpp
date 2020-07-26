// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

//  Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
// Example :


// Given A : [1, 2, 3]
// A height balanced BST  : 

//       2
//     /   \
//    1     3

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBST(const vector<int> &A) 
{
    if(A.empty())
        return NULL;
    
    unsigned int mid = A.size()/2;
    vector<int> leftArr(A.begin(), A.begin()+mid), rightArr(A.begin()+mid+1, A.end());
    
    TreeNode* head=new TreeNode(A[mid]);
    head->left = sortedArrayToBST(leftArr); head->right = sortedArrayToBST(rightArr);
    
    return head;
}

int main()
{
    
}