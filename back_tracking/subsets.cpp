//prakritis code
void helper( vector<vector<int>> &res,int i, vector<int>&sub,vector<int> &A )
{
    if(i==A.size())
    {
        res.push_back(sub);
        return;
    }
    else
    {
        helper(res,i+1,sub,A);
        sub.push_back(A[i]);
        helper(res,i+1,sub,A);
        sub.pop_back();
    }
}
vector<vector<int>> Solution::subsets(vector<int> &A)
{
    vector<vector<int>> res;
    vector<int> sub;
    sort(A.begin(),A.end());
    helper(res,0,sub,A);
    sort(res.begin(),res.end());
    return res;
}

//krutikas code
void r_fxn(vector<int> A,int B,vector<vector<int>>&res,vector<int>temp,int curr)
{
    if(B>=0)
    {
        res.push_back(temp);
    }
    else
    {
        return;
    }
    for(int i=curr;i<A.size();i++)
    {
        temp.push_back(A[i]);
        r_fxn(A,B-1,res,temp,i+1);
        temp.pop_back();
    }

}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>>res;
    vector<int>temp;
    sort(A.begin(),A.end());
    r_fxn(A,A.size(),res,temp,0);
    return res;
}
//editorial code
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

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>> ans;
    sort(A.begin(),A.end());
    int index=0;
    vector<int> temp;
    subset(A,ans,temp,index);
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;

}
