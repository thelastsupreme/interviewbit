//prabhaths code
int Solution::removeDuplicates(vector<int> &A) {
    vector<int>B;
    int flag=0;
    int count=1;
    {
        int i=0;
        for(i;i<A.size()-1;i++)
        {
            if(A[i]!=A[i+1])
               {
                   count++;
                   B.push_back(A[i]);
                   flag=0;
               }
            if(A[i]==A[i+1] && flag==0)
                {
                   count++;
                   B.push_back(A[i]);
                   flag=1;

                }
        }
        B.push_back(A[i]);
    }
    A.clear();
    A=B;
    return count;
}

//krutikas code
int Solution::removeDuplicates(vector<int> &A) {
    int count=1;
    vector<int> B;
    if(A.size()>1)
    {
        int i=0;
        for(i=0;i<A.size()-1;i++)
        {
            if(A[i]!=A[i+1])
            {
               B.push_back(A[i]);
                if(count>1)
               B.push_back(A[i]);
               count=0;

            }
        count++;
        }
        A.clear();
        A=B;
        A.push_back(A[i]);
        if(count>1) A.push_back(A[i]);
    }
    return A.size();
}
//interview bit code
int removeDuplicates(vector<int> &A) {
            for (int i = 0; i < n; i++) {
                if (i < n - 2 && A[i] == A[i+1] && A[i] == A[i+2]) continue;
                else {
                    A[count] = A[i];
                    count++;
                }
            }
            A.resize(count);
            return count;
}
