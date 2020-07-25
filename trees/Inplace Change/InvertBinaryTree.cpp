// Given a binary tree, invert the binary tree and return it.
// Look at the example for more details.

// Example :
// Given binary tree

//      1
//    /   \
//   2     3
//  / \   / \
// 4   5 6   7
// invert and return

//      1
//    /   \
//   3     2
//  / \   / \
// 7   6 5   4

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* invertTree(TreeNode* A) {
    if(A==NULL)
        return NULL;
    TreeNode*temp=A->left;
    A->left=A->right;
    A->right=temp;
    invertTree(A->left);
    invertTree(A->right);
    return A;
}

int main()
{
    
}