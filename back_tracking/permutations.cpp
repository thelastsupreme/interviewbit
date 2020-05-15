//prabhaths code
void permute_helper(vector<int>v,vector<int>perm,vector<vector<int>>&res)
{
    if(v.size()==0)
    {
        res.push_back(perm);
    }
    else
    {
        for(int i=0;i<v.size();i++)
        {
            int s=v[i];         //store string in s
            v.erase(v.begin()+i);  //remove that from main vector
            perm.push_back(s);     //push it into temp vector
            permute_helper(v,perm,res);//recursive call on the changed vectors
            perm.pop_back();       //remove element from temp vector
            v.insert(v.begin()+i,s);//insert element back in main vector
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>>res;
    vector<int>perm;
    permute_helper(A,perm,res);
    return res;
}
//prakritis code
void helper(vector<int> &A, int curr, vector<vector<int> > &v)
{
    if(j >= A.size())
    {
        v.push_back(A);
        return;
    }
    for(auto i=curr; i<A.size(); i++)
    {
        swap(A[curr], A[i]); // 1 2 3
        helper(A, j+1, v);
        swap(A[curr], A[i]);
    }
}
vector<vector<int> > Solution::permute(vector<int> &A)
{
    vector<vector<int> > res;
    helper(A, 0, res);
    return res;
}
