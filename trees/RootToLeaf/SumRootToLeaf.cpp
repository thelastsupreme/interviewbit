// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

// An example is the root-to-leaf path 1->2->3 which represents the number 123.

// Find the total sum of all root-to-leaf numbers % 1003.

// Example :

//     1
//    / \
//   2   3
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.

// Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int helper(TreeNode *A, int val)
{
    if (A == NULL)
        return 0;
    val = (val * 10 + A->val) % 1003;
    if (A->left == NULL && A->right == NULL)
    {
        return (val) % 1003;
    }
    else
    {
        return (helper(A->left, val) % 1003 + helper(A->right, val) % 1003) % 1003;
    }
}
int sumNumbers(TreeNode *A)
{
    return helper(A, 0) % 1003;
}