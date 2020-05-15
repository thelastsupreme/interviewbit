//prabhaths code
int Solution::maxArea(vector<int> &A) {
    if(A.size()==1)
        return 0;
    int i=0;
    int j=A.size()-1;
    int a=0;
    int ans=0;
    while(i<A.size())
    {
        int a=min(A[i],A[j])*(j-i);
        int n=max(A[i],A[j]);
        if(n==A[i])
            j--;
        else if(n==A[j])
            i++;
        ans=max(ans,a);
        if(i==j)
        break;
    }
    return ans;
}

//krutikas code
int Solution::maxArea(vector<int> &A) {

    if(A.size()==0||A.size()==1)
       return 0;
    if(A.size()==2)
    {
        return (A[1]-A[0])*min(A[1],A[0]);
    }
    long long sol;
    long long max=-1;
    long i=0;
    long n=A.size();
    long j=n-1;
    while(i<n)
    {
        while(j>=0)
        {
            sol=(A[i]-A[j])*min(A[j],A[i]);
            if(sol>max)
               max=sol;
            j--;
        }
        j=n-1;
    }
    return max;
}
