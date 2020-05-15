//prabhaths code
int Solution::removeDuplicates(vector<int> &A) {
    vector<int>B;
    int count=1;
    {
        int i=0;
        for(i;i<A.size()-1;i++)
        {
            if(A[i]!=A[i+1])
               {
                   count++;
                   B.push_back(A[i]);
               }
        }
        B.push_back(A[i]);
    }
    A.clear();
    A=B;
    return count;
}
//krutikas code
Solution::removeDuplicates(vector<int> &A) {
    vector<int> B;
    if(A.size()>1)
    {
        int i=0;
        for(i=0;i<A.size()-1;i++)
        {
            if(A[i]!=A[i+1])
                B.push_back(A[i]);
        }
        A.clear();
        A=B;
        A.push_back(A[i]);
    }
    return A.size();
}

//prakritis code
