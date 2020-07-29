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
TreeNode* solve(TreeNode* A, TreeNode* B) {
     if (!A) 
        return B; 
    if (!B) 
        return A; 
    A->val += B->val; 
    A->left = solve(A->left, B->left); 
    A->right = solve(A->right, B->right); 
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
        //       5
        //      / \
        //     4   8
        //    /   / \
        //   11  13  9
        //  /  \      \
        // 7    2      1
    TreeNode *rooA = new TreeNode(5); 
    rooA->left        = new TreeNode(4); 
    rooA->right       = new TreeNode(8); 
    rooA->left->left  = new TreeNode(11);  
    rooA->left->left->left = new TreeNode(7);
    rooA->left->left->right = new TreeNode(2);
    rooA->right->right = new TreeNode(9);
    rooA->right->left=new TreeNode(13);
    rooA->right->right->right = new TreeNode(1);

    TreeNode* res=solve(root,rooA);
    print_inorder(res);
}