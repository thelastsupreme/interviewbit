// Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).

// Example :
// Given binary tree

//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:

// [
//   [3],
//   [9,20],
//   [15,7]
// ]
// Also think about a version of the question where you are asked to do a level order traversal of the tree when depth of the tree is much greater than number of nodes on a level.
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> >levelOrder(TreeNode* a) {
    queue<TreeNode *>q;
    vector<vector<int>> ans;
    if(!a) return ans;
    q.push(a);
    q.push(NULL);
    vector<int> curr;
    while(!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if(temp)
        {
            curr.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        else
        {
            ans.push_back(curr);
            curr.clear();
            if(q.empty()) break;
            q.push(NULL);
        }
    }
    return ans;
}

int main()
{
    
}