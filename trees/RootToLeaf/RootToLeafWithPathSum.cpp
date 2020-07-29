// Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

// For example:
// Given the below binary tree and sum = 22,

//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//editorial best approach
void pathSumHelper(TreeNode *root, int remainingSum, vector<int> &current, vector<vector<int> > &ret) {
    if (root == NULL) return;

    remainingSum -= root->val;
    current.push_back(root->val);

    // If we have reached a leaf, time to check the sum. 
    if (root->left == NULL && root->right == NULL) {
        if (remainingSum == 0) {
            ret.push_back(current);
        }
        current.pop_back();
        return;
    }

    // check the left and the right subtree.
    pathSumHelper(root->left, remainingSum, current, ret);
    pathSumHelper(root->right, remainingSum, current, ret);
    current.pop_back();
    return;
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > ans;
    vector<int> current;
    pathSumHelper(root, sum, current, ans);
    return ans;
}