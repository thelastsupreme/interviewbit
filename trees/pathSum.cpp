#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int hasPathSum(TreeNode* A, int B) {
    int l,r=0;
    // cout<<"A value is "<<A->val<<" ,B value is "<<B<<endl;
    if(A==NULL)
        return 0;
    if(A->left==NULL&&A->right==NULL)
        return A->val==B;

    
    l=hasPathSum(A->left,B-(A->val));
    r=hasPathSum(A->right,B-(A->val));
    if(l||r) return 1;
    return 0;
}

int main(){
        //       5
        //      / \
        //     4   8
        //    /   / \
        //   11  13  4
        //  /  \      \
        // 7    2      1
    TreeNode *root = new TreeNode(5); 
    root->left        = new TreeNode(4); 
    root->right       = new TreeNode(8); 
    root->left->left  = new TreeNode(11);  
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->left=new TreeNode(13);
    root->right->right->right = new TreeNode(1);
    cout<<hasPathSum(root,22);
}
