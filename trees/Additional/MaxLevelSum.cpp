// Problem Description

// Given a Binary Tree denoted by root node A having integer value on nodes. You need to find maximum sum level in it.



// Problem Constraints
// 1 <= number of nodes <= 105

// 1 <= value on nodes <= 105



// Input Format
// First and only argument is a root node of Binary Tree A.



// Output Format
// Return an integer denoting the maximum sum level in the tree.



// Example Input
// Input 1:

//  Tree:      4
//           /   \
//          2     5
//         / \   / \
//        1  3  2   6
// Input 2:

//  Tree:      1
//           /   \
//          2     3
//        /  \     \
//       4    5     8
//                 / \
//                6   7  


// Example Output
// Output 1:

//  12
// Output 2:

//  17


// Example Explanation
// Explanation 1:

//  Sum of all nodes of 0'th level is 4 
//  Sum of all nodes of 1'th level is 7
//  Sum of all nodes of 2'th level is 12
//  Hence maximum sum is 12
// Explanation 2:

//  Sum of all nodes of 0'th level is 1
//  Sum of all nodes of 1'th level is 5
//  Sum of all nodes of 2'th level is 17
//  Sum of all nodes of 3'th level is 13
//  Hence maximum sum is 17
 #include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int MaxSumLevel(TreeNode *node)
{
    int currSum,currLevel=0,maxSum=0,maxLevel=0;
    TreeNode *temp = nullptr;
    TreeNode *marker = new TreeNode('#');
    queue<TreeNode *> q;
    if (!node)
        return 0;
    q.push(node);
    q.push(marker);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->val == '#'&&q.size()>0) //checking q.size() so as to not create an infinte loop
        {
            maxSum=max(maxSum,currSum);
            currSum=0;             //reset currSum
            q.push(marker);
        }

        else if (temp->val=='#')        //for the last marker
        {
            return maxSum;
        }
        
        else
        {
            currSum+=temp->val;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        cout<<" maxSum : "<<maxSum<<" curSum : "<<currSum<<endl;
    }
}

//fastest way is using a vector
// int Solution::solve(TreeNode* A) 
// {
//     int i, sum, max ;
//     vector<TreeNode*> lev, nexlev ;
    
//     max = INT_MIN ;
//     nexlev.push_back (A) ;
//     do
//     {
//         lev = nexlev ;
//         nexlev.clear () ;
//         sum = 0 ;
//         for (i = 0 ; i < lev.size() ; i++)
//         {
//             sum += lev[i]->val ;
//             if (lev[i]->left)
//                 nexlev.push_back (lev[i]->left) ;
//             if (lev[i]->right)
//                 nexlev.push_back (lev[i]->right) ;
//         }
        
//         if (sum > max)
//             max = sum ;
//     } while (nexlev.size()) ;
    
//     return max ;
// }

int main(){
    TreeNode *root=new TreeNode(17);
    root->left=new TreeNode(41);
    root->right=new TreeNode(9);
    root->left->left=new TreeNode(29);
    root->left->right=new TreeNode(6);
    root->right->left=new TreeNode(81);
    root->right->right=new TreeNode(40);
    root->right->right->right=new TreeNode(121);
    root->right->right->right->right=new TreeNode(22);
    cout<<MaxSumLevel(root); //op 156
}