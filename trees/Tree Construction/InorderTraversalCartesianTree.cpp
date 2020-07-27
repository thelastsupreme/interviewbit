// Given an inorder traversal of a cartesian tree, construct the tree.

//  Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
//  Note: You may assume that duplicates do not exist in the tree. 
// Example :

// Input : [1 2 3]

// Return :   
//           3
//          /
//         2
//        /
//       1
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//if u dont want to split array and use additional memory
//you can go for writing a helper function and passing the indices
TreeNode* buildTree(vector<int> &A) 
{
    if(A.empty())
        return NULL;
    
    auto imx = max_element(A.begin(), A.end());
    vector<int> leftArr(A.begin(), imx), rightArr(imx+1, A.end());
    
    TreeNode* head=new TreeNode(*imx);
    head->left = buildTree(leftArr); head->right = buildTree(rightArr);
    
    return head;
}

int main()
{

}