// Given inorder and postorder traversal of a tree, construct the binary tree.

//  Note: You may assume that duplicates do not exist in the tree. 
// Example :

// Input : 
//         Inorder : [2, 1, 3]
//         Postorder : [2, 3, 1]

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

TreeNode * build(vector<int> &a, vector<int> &b, int &post,unordered_map<int,int> &m,int start,int end)
 {
    if(start>end) return NULL;
    int curr = b[post--];
    TreeNode *root = new TreeNode(curr);
    if(start == end) return root;
    root->right = build(a,b,post,m,m[curr]+1,end);
    root->left = build(a,b,post,m,start,m[curr]-1);
    return root;
 }

TreeNode* buildTree(vector<int> &a, vector<int> &b) {
    unordered_map<int,int> m;
    for(int i=0; i<a.size(); i++)
    {
        m[a[i]] = i;
    }
    int x= b.size()-1;
    return build(a,b,x,m,0,a.size()-1);
}

int main()
{
    
}