// Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

// Return 1 to denote that two such nodes exist. Return 0, otherwise.

// Notes

// Your solution should run in linear time and not take memory more than O(height of T).
// Assume all values in BST are distinct.
// Example :

// Input 1: 

// T :       10
//          / \
//         9   20

// K = 19

// Return: 1

// Input 2: 

// T:        10
//          / \
//         9   20

// K = 40

// Return: 0

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//using O(N)

// void GetData(TreeNode* A,int B,map<int,bool> &mp)
// {
//     if(A==NULL) return;
//     GetData(A->left,B,mp);
//     if(mp.find(B-(A->val))==mp.end())
//     mp[A->val]=false;
//     else mp[A->val]=true;
//     GetData(A->right,B,mp);
// }
// int t2Sum(TreeNode* A, int B) {
//     map<int,bool> mp;
//     GetData(A,B,mp);
//     for(auto i : mp)
//     if(i.second==true) return 1;
//     return 0;
// }

//in O(height) complexity but O(N^2)
int t2Sum(TreeNode* A, int B) {
    stack<TreeNode * > s1;
    stack<TreeNode * > s2;
    int val1=0,val2=0;
    TreeNode *curr1=A,*curr2=A;
    bool done1=false,done2=false;
    while(1)
    {
        while(done1==false)
        {
            if(curr1!=NULL)
            {
                s1.push(curr1);
                curr1=curr1->left;
            }
            else
            {
                if(s1.empty())
                 done1=1;
                 else
                 {
                     curr1=s1.top();
                     s1.pop();
                     val1=curr1->val;
                     curr1=curr1->right;
                     done1=1;
                 }
            }
        }
        while(done2==false)
        {
            if(curr2!=NULL)
            {
                s2.push(curr2);
                curr2=curr2->right;
            }
            else
            {
                if(s2.empty())
                done2=1;
                else
                {
                    curr2=s2.top();
                    s2.pop();
                    val2=curr2->val;
                    curr2=curr2->left;
                    done2=1;
                }
            }
        }
        if((val1!=val2)&& (val1+val2==B)) return 1;
        else if(val1+val2>B)
          done2=false;
        else if(val1+val2<B)
        done1=false;
        if(val1>=val2)
         return 0;
        
    }
}
int main()
{
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(14);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(20);
    // root->left->right=new TreeNode(6);
    // root->right->left=new TreeNode(81);
    // root->right->right=new TreeNode(40);
    // root->right->right->right=new TreeNode(121);
    cout << t2Sum(root, 21);
}
