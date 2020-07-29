// Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

// Example :
// Given binary tree

//     3
//    / \
//   9  20
//     /  \
//    15   7
// return

// [
//          [3],
//          [20, 9],
//          [15, 7]
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

vector<vector<int> >zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>result;
    vector<int>t;
    TreeNode* temp;
    int leftToRight=1;        //flag for direction
    if(!root)
        return result;
    stack<TreeNode*>currLevel;
    stack<TreeNode*>nextLevel;
    currLevel.push(root);
    while(!currLevel.empty())
    {
        temp=currLevel.top();
        currLevel.pop();

        if(temp)
        {
            t.push_back(temp->val);
            if (leftToRight)
            {
                if(temp->left)
                    nextLevel.push(temp->left);
                if (temp->right)
                    nextLevel.push(temp->right);
            }
            else
            {
                if(temp->right)
                    nextLevel.push(temp->right);
                if (temp->left)
                    nextLevel.push(temp->left);
            }   
        }
        if (currLevel.empty())
        {
            leftToRight=1-leftToRight;       //toggle 
            swap(currLevel,nextLevel);
            result.push_back(t);
            t.clear();
        }
        
    }
    return result;
}