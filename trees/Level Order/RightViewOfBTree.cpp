// Problem Description

// Given a binary tree A of integers. Return an array of integers representing the right view of the Binary tree.

// Right view of a Binary Tree: is a set of nodes visible when the tree is visited from Right side.



// Problem Constraints
// 1 <= Number of nodes in binary tree <= 105

// 0 <= node values <= 109



// Input Format
// First and only argument is an pointer to the root of binary tree A.



// Output Format
// Return an integer array denoting the right view of the binary tree A.



// Example Input
// Input 1:

//         1
//       /   \
//      2    3
//     / \  / \
//    4   5 6  7
//   /
//  8 
// Input 2:

//     1
//    /  \
//   2    3
//    \
//     4
//      \
//       5


// Example Output
// Output 1:

//  [1, 3, 7, 8]
// Output 2:

//  [1, 3, 4, 5]

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(vector<int>A)
{
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<" ";
    cout<<endl;
}


vector<int>rightView(TreeNode* node)
{
    vector<int>result;
    TreeNode *temp = nullptr;
    TreeNode *marker = new TreeNode('#');
    queue<TreeNode *> q;
    if (!node)
        return result;
    q.push(node);
    q.push(marker);
    while (!q.empty())
    {
        // print(result);
        temp = q.front();
        q.pop();

        if(!q.empty()&&q.front()->val=='#')
            result.push_back(temp->val);

        if (temp->val=='#'&&q.empty())        //for the last marker
        {
            break;
        }
        if (temp->val == '#') //checking q.size() so as to not create an infinte loop
        {
            q.push(marker);
            // cout << endl;
        }
        else
        {
            // cout << temp->val << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return result;
}

//using pair of node and level
vector<int>solve(TreeNode *A)
{
    vector<int> ans;
    if (!A)
        return ans;
    int value, prev = 0; //prev is used to check if new level is encountered
    queue<pair<TreeNode *, int>> Q;
    Q.push(make_pair(A, 0));

    while (!Q.empty())
    {
        TreeNode *node = Q.front().first;
        int level = Q.front().second;
        Q.pop();
        if (level != prev)
        {
            ans.push_back(value);
            prev = level;
        }
        value = node->val;
        if (node->left)
            Q.push(make_pair(node->left, level + 1));
        if (node->right)
            Q.push(make_pair(node->right, level + 1));
    }
    ans.push_back(value);

    return ans;
}

int main()
{
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    root->left->left->left=new TreeNode(8);
    vector<int>ans=rightView(root);
    print(ans);
}
