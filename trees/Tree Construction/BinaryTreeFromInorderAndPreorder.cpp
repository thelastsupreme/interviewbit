// Given preorder and inorder traversal of a tree, construct the binary tree.

//  Note: You may assume that duplicates do not exist in the tree. 
// Example :

// Input :
//         Preorder : [1, 2, 3]
//         Inorder  : [2, 1, 3]

// Return :
//             1
//            / \
//           2   3

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeHelper(vector<int>&preOrder,vector<int>&inOrder,int start,int end,int &preOrderIndex,unordered_map<int,int>&m)
{
    if(start>end)
        return nullptr;
    TreeNode* newNode=new TreeNode(preOrder[preOrderIndex++]);
    if (start==end)
    {
        return newNode;
    }
    int inOrderIndex=m[newNode->val];
    newNode->left=buildTreeHelper(preOrder,inOrder,start,inOrderIndex-1,preOrderIndex,m);
    newNode->right=buildTreeHelper(preOrder,inOrder,inOrderIndex+1,end,preOrderIndex,m);
    return newNode;
}

TreeNode* buildTree(vector<int> &A, vector<int> &B) {
    unordered_map<int,int> m;
    for(int i=0; i<A.size(); i++)
    {
        m[B[i]] = i;
    }
    int x=0;
    return buildTreeHelper(A,B,0,A.size()-1,x,m);
}

int main()
{
    
}