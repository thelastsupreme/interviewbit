#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void print_vect(vector<vector<int> >&input)
{
	for (int i = 0; i < input.size(); i++) {
		for(int j=0;j<input[i].size();j++)
        {
            cout << input[i][j] << ' ';
        }
        cout<<endl;
	}
}
map<int,vector<int>>m;   //used a map instead of a vector cause we have no idea of the left most node location

void VerticalTraverse(TreeNode* root,int col)
{
    if(root==nullptr)
        return;
    VerticalTraverse(root->left,col-1);
    m[col].push_back(root->val);
    VerticalTraverse(root->right,col+1);
}
vector<vector<int> > verticalOrderTraversal(TreeNode* A) {
    vector<vector<int>>result;
    m.clear();
    VerticalTraverse(A,0);
    auto it=m.begin();
    while(it!=m.end())
    {
        result.push_back(it->second);
        it++;
    }
    for(int i=0;i<result.size();i++)
        reverse(result[i].begin(),result[i].end());
    return result;
}

int main()
{
    TreeNode *root=new TreeNode(9);
    root->left=new TreeNode(818);
    root->left->left=new TreeNode(2510);
    root->left->right=new TreeNode(212);
    root->left->right->left=new TreeNode(9881);
    vector<vector<int>>result=verticalOrderTraversal(root);
    print_vect(result);
}