#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print_preorder(TreeNode *node)
{
    stack<TreeNode *> s;
    while (1)
    {
        while (node)
        {
            cout << node->val << " ";
            s.push(node);
            node = node->left;
        }
        if (s.empty())
            break;
        node = s.top();
        s.pop();
        node = node->right;
    }
}
 
void print_inorder(TreeNode* node)
{
    stack<TreeNode*>s;
    while (1)
    {
        while (node)
        {
            s.push(node);
            node=node->left;
        }
        if(s.empty())
            break;
        node=s.top();
        s.pop();
        cout<<node->val<<" ";
        node=node->right;
    }
    
}

void print_postorder(TreeNode* node)
{
    stack<TreeNode*>s;
    TreeNode* prev=nullptr;
    do
    {
        while (node)
        {
            s.push(node);
            node=node->left;
        }
        while (node==nullptr&&!s.empty())
        {
            node=s.top();
            if(node->right==nullptr||node->right==prev)
            {
                cout<<node->val<<" ";
                s.pop();
                prev=node;
                node=nullptr;
            }
            else
            {
                node=node->right;
            }
        }   
    } while (!s.empty());
    
}

void print_levelorder(TreeNode *node)
{
    TreeNode* temp=nullptr;
    queue<TreeNode *> q;
    if (!node)
        return;
    q.push(node);
    while (!q.empty())
    {
        temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

//to print with level seperation use a marker like a character
void print_levelorder_Seperation(TreeNode *node)
{
    TreeNode *temp = nullptr;
    TreeNode *marker = new TreeNode('#');
    queue<TreeNode *> q;
    if (!node)
        return;
    q.push(node);
    q.push(marker);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->val == '#'&&q.size()>0) //checking q.size() so as to not create an infinte loop
        {
            q.push(marker);
            cout << endl;
        }

        else if (temp->val=='#')        //for the last marker
        {
            return;
        }
        
        else
        {
            cout << temp->val << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
//O(N^2)
void levelOrder_best(TreeNode *A)
{
    queue<TreeNode *> q;
    if (A == NULL)
        return;
    q.push(A);
    q.push(NULL);
    while (!q.empty() && q.front() != NULL)
    {
        while (q.front() != NULL)
        {
            TreeNode *front = q.front();
            q.pop();
            cout<<front->val<<" ";
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        cout<<endl;
        q.pop();
        q.push(NULL);
    }
    return;
}
int main(){
    TreeNode *root=new TreeNode(17);
    root->left=new TreeNode(41);
    root->right=new TreeNode(9);
    root->left->left=new TreeNode(29);
    root->left->right=new TreeNode(6);
    root->right->left=new TreeNode(81);
    root->right->right=new TreeNode(40);
    root->right->right->right=new TreeNode(121);
    cout<<"pre_order_print :"<<endl;
    print_preorder(root);
    cout<<"\nin_order_print :"<<endl;
    print_inorder(root);
    cout<<"\npost_order_print :"<<endl;
    print_postorder(root);
    cout<<"\nlevel_order_print :"<<endl;
    print_levelorder(root);
    cout<<"\nlevel_order_print_with_level_sepaerations :"<<endl;
    levelOrder_best(root);
}