// Problem Description

// Given a binary tree, return the reverse level order traversal of its nodes values. (i.e, from left to right and from last level to starting level).



// Problem Constraints
// 1 <= number of nodes <= 5 * 105

// 1 <= node value <= 105



// Input Format
// First and only argument is a pointer to the root node of the Binary Tree, A.



// Output Format
// Return an integer array denoting the reverse level order traversal from left to right.



// Example Input
// Input 1:

//     3
//    / \
//   9  20
//     /  \
//    15   7
// Input 2:

//    1
//   / \
//  6   2
//     /
//    3


// Example Output
// Output 1:

//  [15, 7, 9, 20, 3] 
// Output 2:

//  [3, 6, 2, 1]


// Example Explanation
// Explanation 1:

//  Nodes as level 3 : [15, 7]
//  Nodes at level 2: [9, 20]
//  Nodes at level 1: [3]
//  Reverse level order traversal will be: [15, 7, 9, 20, 3]
// Explanation 2:

//  Nodes as level 3 : [3]
//  Nodes at level 2: [6, 2]
//  Nodes at level 1: [1]
//  Reverse level order traversal will be: [3, 6, 2, 1]
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void print_reverse_levelorder(TreeNode *node)
{
    TreeNode* temp=nullptr;
    stack<int>s;
    queue<TreeNode *> q;
    if (!node)
        return;
    q.push(node);
    while (!q.empty())
    {
        temp=q.front();
        q.pop();
        s.push(temp->val);
        
        if(temp->right)
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);
    }
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }  
}
int main(){
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    print_reverse_levelorder(root);
}