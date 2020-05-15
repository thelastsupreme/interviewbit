vector<int> Solution::twoSum(const vector<int> &A, int B) {
    vector<int>res;
    if(A.size()<2)
        return res;
    unordered_map<int,int>m;
    for(int i=0;i<A.size();i++)
    {
        int temp=B-A[i];
        if(m.find(temp)!=m.end())
        {
            res.push_back(m[temp]+1);
            res.push_back(i+1);
            return res;
        }
        if(m.find(A[i])==m.end())
            m[A[i]]=i;
    }
    return res;

}
