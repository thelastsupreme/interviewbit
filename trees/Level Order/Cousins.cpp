// Problem Description

// Given a Binary Tree A consisting of N nodes.

// You need to find all the cousins of node B.

// NOTE:

// Siblings should not be considered as cousins.
// Try to do it in single traversal.
// You can assume that Node B is there in the tree A.
// Order doesn't matter in the output.


// Problem Constraints
// 1 <= N <= 105

// 1 <= B <= N



// Input Format
// First Argument represents the root of binary tree A.

// Second Argument is an integer B denoting the node number.



// Output Format
// Return an integer array denoting the cousins of node B.

// NOTE: Order doesn't matter.



// Example Input
// Input 1:

//  A =

//            1
//          /   \
//         2     3
//        / \   / \
//       4   5 6   7 


// B = 5

// Input 2:

//  A = 
//             1
//           /   \
//          2     3
//         / \ .   \
//        4   5 .   6


// B = 1




// Example Output
// Output 1:

//  [6, 7]
// Output 2:

//  []


// Example Explanation
// Explanation 1:

//  Cousins of Node 5 are Node 6 and 7 so we will return [6, 7]
//  Remember Node 4 is sibling of Node 5 and do not need to return this.
// Explanation 2:

//  Since Node 1 is the root so it doesn't have any cousin so we will return an empty array.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//my solution
vector<int>solve(TreeNode* A, int B) {
    vector<int>res;
    TreeNode* marker=new TreeNode(INT_MAX);
    bool found=false;
    queue<TreeNode*>q;
    q.push(A);
    q.push(marker);
    while(!q.empty()){
        if(q.front()->val==INT_MAX){ //when u hit a marker
            if(found){     //if found flag is true
                q.pop();   //pop the marker
                while(!q.empty()){
                    if(q.front()->val!=B)
                        res.push_back(q.front()->val);
                    q.pop();
                }
                return res;
            }else{
                q.pop(); //just pop the marker
                q.push(marker);//insert new marker for next level
            }
        }
        
        if(q.front()->left&&q.front()->left->val==B){
            found=true;
            q.push(q.front()->left);
        }else if(q.front()->right&&q.front()->right->val==B){
            found=true;
            q.push(q.front()->right);
        }else{
            if(q.front()->left)
                q.push(q.front()->left);
            if(q.front()->right)   
                q.push(q.front()->right);
        }
        q.pop();
    }
    
}

//editorial
vector<int> solve_1(TreeNode *A, int B)
{

    if (A->val == B)
    {
        return {};
    }
    queue<TreeNode *> q;
    q.push(A);
    bool found = false;
    int size = 0;
    while (!q.empty() && !found)
    {
        size = q.size();

        while (size--)
        {
            TreeNode *p = q.front();
            q.pop();

            if (p->left && p->left->val == B)
                found = true;
            else if (p->right && p->right->val == B)
            {
                found = true;
            }
            else
            {
                if (p->left)
                {
                    q.push(p->left);
                }
                if (p->right)
                {
                    q.push(p->right);
                }
            }
        }
        if (found)
            break;
    }
    vector<int> ans;
    while (q.size())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }

    return ans;
}