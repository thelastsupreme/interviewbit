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

void print_inorder(TreeNode* node)
{
    if(node!=nullptr)
    {
        print_inorder(node->left);
        cout<<node->val<<endl;
        print_inorder(node->right);
    }
}

TreeNode* flatten(TreeNode* A) {
    if(A==NULL)
        return NULL;
    A->left=flatten(A->left);
    A->right=flatten(A->right);
    TreeNode* temp=A->right;
    A->right=A->left;
    A->left==NULL;
       
    TreeNode* curr=A;
    while(curr->right!=NULL)
        curr=curr->right;
    curr->right=temp;
    return A;
}


int main(){
        //       1
        //      / \
        //     2   5
        //    / \   \
        //   3   4    6
    TreeNode *root = new TreeNode(1); 
    root->left        = new TreeNode(2); 
    root->right       = new TreeNode(5); 
    root->left->left  = new TreeNode(3);  
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    TreeNode* res=flatten(root);
    print_inorder(res);
}