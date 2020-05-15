vector<int> Solution::prevSmaller(vector<int> &A) {
    int n=A.size();
    vector<int>res(n,-1);
    stack<int>s;
    for(int i=0;i<n;i++)
        {
            while(!s.empty()&&s.top()>=A[i])
                s.pop();
            if(!s.empty())
            {
                res[i]=s.top();
            }
            s.push(A[i]);
        }
    return res;
}
