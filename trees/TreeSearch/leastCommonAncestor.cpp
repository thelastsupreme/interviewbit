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

//my code

// int helper(TreeNode*A,int B,int C,bool &b,bool &c){
//     if(A==NULL)
//         return -1;
//     int l=helper(A->left,B,C,b,c);
//     int r=helper(A->right,B,C,b,c);
//     cout<<"for A : "<<A->val<<"  l : "<<l<<"  r : "<<r<<endl;
//     if(l==-1&&r==-1){
//         if(A->val==B){
//             b=true;
//             return A->val;
//         }
//         if(A->val==C){
//             c=true;
//             return A->val;
//         }  
//         return -1;
//     }
//     if((l==B||l==C)&&(r==B||r==C))
//         return A->val;
//     if(A->val==B)
//     {
//         b=true;
//         if(l==C||r==C)
//             return B;
//     }
//     if(A->val==C)
//     {
//         c=true;
//         if(l==B||r==B)
//             return C;
//     }
//     if((l!=-1)&&r==-1)
//         return l;
//     if(r!=-1&&l==-1)
//         return r;
//     if(A->val==B||A->val==C){
//         return A->val;
//     }   
// }
// int lca(TreeNode* A, int B, int C) {
//    bool b=false;
//    bool c=false;
//   int res=helper(A,B,C,b,c);
//   if(B==C&&(b||c))
//     return B;
//   if(b&&c)
//     return res;
//   return -1;
// }
int Lca(TreeNode *root, int a, int b) {
    if (root == NULL) return -1;
    if (root -> val == a || root -> val == b) return root -> val;
    int left = Lca(root -> left, a, b);
    int right = Lca(root -> right, a, b);
    if (left != -1 && right != -1) return root -> val;
    return (left != -1 ? left : right);
}

bool find(TreeNode *root, int v) {
    if (root == NULL) return false;
    if (root -> val == v) return true;
    return (find(root -> left, v) || find(root -> right, v));
}

int lca(TreeNode* root, int a, int b) {
    if (!find(root, a) || !find(root, b)) return -1;
    return Lca(root, a, b);
}

int main(){
        //       5
        //      / \
        //     4   8
        //    /   / \
        //   11  13  9
        //  /  \      \
        // 7    2      1
    TreeNode *root = new TreeNode(5); 
    root->left        = new TreeNode(4); 
    root->right       = new TreeNode(8); 
    root->left->left  = new TreeNode(11);  
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right = new TreeNode(9);
    root->right->left=new TreeNode(13);
    root->right->right->right = new TreeNode(1);
    cout<<lca(root,13,14);
}