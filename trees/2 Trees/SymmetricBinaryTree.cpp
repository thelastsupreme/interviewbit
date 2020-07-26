// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// Example :

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// The above binary tree is symmetric.
// But the following is not:

//     1
//    / \
//   2   2
//    \   \
//    3    3
// Return 0 / 1 ( 0 for false, 1 for true ) for this problem

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isMirror(TreeNode* root1,TreeNode* root2)
{
    if(!root1&&!root2)
        return true;
    if(!root1||!root2)
        return false;
    if(root1->val!=root2->val)
        return false;
    return(isMirror(root1->left,root2->right)&&isMirror(root1->right,root2->left));
}

int isSymmetric(TreeNode* A) {
    return isMirror(A,A);
}
int main()
{

}