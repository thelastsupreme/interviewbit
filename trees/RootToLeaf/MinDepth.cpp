// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

//  NOTE : The path has to end on a leaf node. 
// Example :

//          1
//         /
//        2
// min depth = 2.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* A) {
    if(A==NULL)
        return 0;
    if(A->left==NULL)
        return 1+minDepth(A->right);
    if(A->right==NULL)
        return 1+minDepth(A->left);
    return 1+min(minDepth(A->right),minDepth(A->left));
}
