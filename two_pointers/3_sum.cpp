int Solution::threeSumClosest(vector<int> &A, int B) 
{
    sort(A.begin(), A.end());
    auto n = A.size();
    int diff = INT_MAX;
    int res = 0;
    for (auto i = 0; i<n-2; ++i)
    {
        int l = i+1, r = n-1;
        while (l<r)
        {
            auto sum = A[i] + A[l] + A[r];
            auto diff2 = sum>B ? sum-B : B-sum;
            if(diff2==0)
            {
                return B;
            }
            if(diff2<diff)
            {
                res = sum; 
                diff = diff2;
            }
            if(sum>B)
                --r;
            else
                ++l;
        }

    }
    return res;

}
//krutikas code
int Solution::threeSumClosest(vector<int> &A, int B) {
   
    int min=INT_MAX;
    sort(A.begin(),A.end());
    vector<int> v;
    unordred_map<int,int> m;
    for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            v.push_back(A[i]+A[j]);
        }
    }
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            int sum=0;
            sum=A[i]+v[j];
            if(abs(sum-B)<min)
            {
               
            }
        }
    }
    return min;
}