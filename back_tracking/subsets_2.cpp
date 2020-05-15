void subset(vector<int> &A,vector<vector<int>> &ans,vector<int> temp,int index)
{
    //insert
    ans.push_back(temp);

    for(int i=index;i<A.size();i++)
    {
        temp.push_back(A[i]);
        subset(A,ans,temp,i+1);
        temp.pop_back();
    }
    return;
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<vector<int>> ans;
    sort(A.begin(),A.end());
    int index=0;
    vector<int> temp;
    subset(A,ans,temp,index);
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}
