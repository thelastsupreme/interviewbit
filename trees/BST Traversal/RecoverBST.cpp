// Two elements of a binary search tree (BST) are swapped by mistake.
// Tell us the 2 values swapping which the tree will be restored.

//  Note:
// A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
// Example :


// Input : 
//          1
//         / \
//        2   3

// Output : 
//        [1, 2]

// Explanation : Swapping 1 and 2 will change the BST to be 
//          2
//         / \
//        1   3
// which is a valid BST    

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void call(TreeNode* A, vector<pair<int, int>> &result, int &prev)
{
    if (A == NULL)
        return;
    call(A->left, result, prev);
    if (A->val < prev)
    {
        result.push_back({prev, A->val});
    }
    prev = A->val;
    call(A->right, result, prev);
}

vector<int>recoverTree(TreeNode* A)
{
    vector<pair<int, int>> result;
    int prev = 0;
    call(A, result, prev);
    vector<int>rst;
    if (result.size() == 1)
    {
        rst.push_back(result[0].second);
        rst.push_back(result[0].first);
    }
    else
    {
        rst.push_back(result[1].second);
        rst.push_back(result[0].first);
    }
    return rst;
}
int main()
{

}