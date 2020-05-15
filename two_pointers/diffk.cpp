int Solution::diffPossible(vector<int> &A, int B) {
    int i=0;
    int j=0;
    if(A.size()==1)
    {
        return 0;
    }
    while(j<A.size())
    {
        if(i==j)
            j++;
        else if(i!=j && abs(A[i]-A[j])==B)
            return 1;
        else if(abs(A[i]-A[j])<B)
            j++;

        else if(abs(A[i]-A[j])>B)
            i++;
    }
    return 0;
}

