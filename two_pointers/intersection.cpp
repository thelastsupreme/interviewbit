//prabhaths ,prakritis code
vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int m=A.size();
    int n=B.size();
    int p1,p2=0;
    vector<int>res;
    while(p1<m&&p2<n)
    {
        if(A[p1]==B[p2])
            {
                res.push_back(A[p1]);
                p1++;
                p2++;
            }
        else if(A[p1]<B[p2])
            p1++;
        else
            p2++;

    }
    return res;
}
//krutikas code
vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {

    int n=min(A.size(),B.size());
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        if(A.size()>B.size())
        {
            if(find(A.begin(),A.end(),B[i])!=A.end())
             {  v.push_back(B[i]);

             }
            /*if(find(A.begin(),A.end(),B[j])!=A.end())
             v.push_back(B[j]);*/
        }
        else
        {
            if(find(B.begin(),B.end(),A[i])!=B.end())
            {  v.push_back(A[i]);

            }
            /*if(find(B.begin(),B.end(),A[j])!=B.end())
             v.push_back(A[j]);*/
        }
    }
    sort(v.begin(),v.end());
    return v;

}
