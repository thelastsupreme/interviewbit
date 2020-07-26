#include <bits/stdc++.h>
using namespace std;

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode* next; //new link
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL) {}
};

void connect(TreeLinkNode *A)
{
    queue<TreeLinkNode *> q;
    if (A == NULL)
        return;
    q.push(A);
    q.push(NULL);
    while (!q.empty() && q.front() != NULL)
    {
        while (q.front() != NULL)
        {
            TreeLinkNode *front = q.front();
            q.pop();
            front->next = q.front();

            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        q.pop();
        q.push(NULL);
    }
    return;
}
int main()
{
    
}
