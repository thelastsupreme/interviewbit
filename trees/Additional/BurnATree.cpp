// Given a binary tree denoted by root node A and a leaf node B from this tree.

// It is known that all nodes connected to a given node (left child, right child and parent) get burned in 1 second. Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on.

// You need to find the minimum time required to burn the complete binary tree.



// Problem Constraints
// 2 <= number of nodes <= 105

// 1 <= node value, B <= 105

// node value will be distinct



// Input Format
// First argument is a root node of the binary tree, A.

// Second argument is an integer B denoting the node value of leaf node.



// Output Format
// Return an integer denoting the minimum time required to burn the complete binary tree.



// Example Input
// Input 1:

//  Tree :      1 
//             / \ 
//            2   3 
//           /   / \
//          4   5   6
//  B = 4
// Input 2:

//  Tree :      1
//             / \
//            2   3
//           /     \
//          4       5 
//  B = 5 


// Example Output
// Output 1:

//  4
// Output 2:

//  4


// Example Explanation
// Explanation 1:

//  After 1 sec: Node 4 and 2 will be burnt. 
//  After 2 sec: Node 4, 2, 1 will be burnt.
//  After 3 sec: Node 4, 2, 1, 3 will be burnt.
//  After 4 sec: Node 4, 2, 1, 3, 5, 6(whole tree) will be burnt.
 
// Explanation 2:

//  After 1 sec: Node 5 and 3 will be burnt. 
//  After 2 sec: Node 5, 3, 1 will be burnt.
//  After 3 sec: Node 5, 3, 1, 2 will be burnt.
//  After 4 sec: Node 5, 3, 1, 2, 4(whole tree) will be burnt.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int dfs(TreeNode *A, int &h, int &ans, int B)
{
    if (!A)
        return 0;

    int hr = 0, hl = 0;

    bool leftfire = false, rightfire = false;

    leftfire = dfs(A->left, hl, ans, B);
    rightfire = dfs(A->right, hr, ans, B);

    if (!leftfire && !rightfire)
        h = max(hr, hl) + 1;

    else if (leftfire)
        h = hl + 1;
        
    else
        h = hr + 1;

    if (B == A->val || leftfire || rightfire)
    {
        ans = max(ans, hr + hl + 1);
        return 1;
    }
    return 0;
}

int solve(TreeNode *A, int B)
{
    int ans = 0, h = 0;
    dfs(A, h, ans, B);
    return ans - 1;
}

int main()
{

}