// Consider lines of slope -1 passing between nodes.

// Given a Binary Tree A containing N nodes, return all diagonal elements in a binary tree belonging to same line.

// NOTE:

// See Sample Explanation for better understanding.
// Order does matter in the output.
// To get the same order as in the output traverse the tree same as we do in pre-order traversal.


// Problem Constraints
// 0 <= N <= 105



// Input Format
// First and only Argument represents the root of binary tree A.



// Output Format
// Return a 1D array denoting the diagonal traversal of the tree.



// Example Input
// Input 1:

//             1
//           /   \
//          4      2
//         / \      \
//        8   5      3
//           / \    /
//          9   7  6
// Input 2:

//              11
//           /     \
//          20      12
//         / \       \
//        1   15      13
//           /  \     /
//          2    17  16
//           \   /
//           22 34


// Example Output
// Output 1:

//  [1, 2, 3, 4, 5, 7, 6, 8, 9]
// Output 2:

//  [11, 12, 13, 20, 15, 17, 16, 1, 2, 22, 34]
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

void print(vector<int>A){
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
map<int,vector<int>>mem;
void helper(TreeNode* A,int idx){
    // cout<<"called helper "<<endl;
    if(A==NULL)
        return;
    mem[idx].push_back(A->val);
    helper(A->left,idx+1);
    helper(A->right,idx);
}
vector<int>solve(TreeNode* A) {
    vector<int>res;
    mem.clear();
    helper(A,0);
    auto it=mem.begin();
    while(it!=mem.end()){
        res.insert(res.end(),it->second.begin(),it->second.end());
        it++;
    }
    return res;
}

int main(){
    //         1
    //       /   \
    //      4      2
    //     / \      \
    //    8   5      3
    //       / \    /
    //      9   7  6
    TreeNode *root = new TreeNode(1); 
    root->left        = new TreeNode(4); 
    root->right       = new TreeNode(2); 
    root->left->left  = new TreeNode(8); 
    root->left->right = new TreeNode(5); 
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(3);
    root->right->right->left = new TreeNode(6);
    vector<int>res=solve(root);
    print(res);
}


   

 