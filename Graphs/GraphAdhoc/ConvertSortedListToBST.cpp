// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

//  A height balanced BST : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
// Example :


// Given A : 1 -> 2 -> 3
// A height balanced BST  :

//       2
//     /   \
//    1     3

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


TreeNode* rec(ListNode * A)
{
    if(!A) return NULL;
    ListNode *fast =A,*slow=A,*prev=NULL; //use fast and slow pointer and get to mid
    while(fast->next!=NULL)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next;
        if(fast->next) fast=fast->next;
    }               
    TreeNode *root=NULL;
    if(slow) root=new TreeNode(slow->val); //start building with mid
    if(root)
    {
        ListNode *t = slow->next;
        if(prev)
        {
            prev->next=NULL; //now break the list at prev
            root->left=rec(A);//now find left again recursively
        }
        if(t) root->right=rec(t); //next node after slow is right subtree 
    }
    return root;
}
TreeNode* sortedListToBST(ListNode* A) {
   TreeNode *root = rec(A);
   return root;
}

int main()
{

}