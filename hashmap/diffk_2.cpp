//prabhaths code
int Solution::diffPossible(const vector<int> &A, int B) {
    if(A.size()<2)
        return 0;
    unordered_map<int,int>m;
    for(int i=0;i<A.size();i++)
    {
        int temp1=A[i]-B;
        int temp2=A[i]+B;
        if(m.find(temp1)!=m.end())
            return 1;
        if(m.find(temp2)!=m.end())
            return 1;
        m[A[i]]=i;

    }
    return 0;
}

//krutikas code
int Solution::diffPossible(const vector<int> &A, int B) {

    unordered_map<int,int> m;
    if(A.size()<2)
      return 0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            m[abs(A[i]-A[j])]=1;
        }
        if(m.find(B)!=m.end())
          return 1;
    }
    return 0;
}
