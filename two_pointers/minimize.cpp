//prabhaths code
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int res=INT_MAX;
    int a=0;
    int minn=0;
    int i=0;
    int j=0;
    int k=0;
    while(i<A.size()&&j<B.size()&&k<C.size())
    {
        a=abs(max(A[i],max(B[j],C[k]))-min(A[i],min(B[j],C[k])));
        res=min(res,a);

        minn=min(A[i],min(B[j],C[k]));
        if(minn==A[i])
            i++;
        else if(minn==B[j])
            j++;
        else if(minn==C[k])
            k++;
    }
    return res;
}

//prakritis code
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
int i = A.size()-1,j=B.size()-1,k=C.size()-1;
    int lowlim =INT_MAX;
    while(i!=-1 && j!=-1 && k!=-1)
    {
        int maxval= max(A[i],max(B[j],C[k]));
        int minval= min(A[i],min(B[j],C[k]));

        int c= abs(maxval-minval);
        lowlim=min(c,lowlim);
        int maxx= max(A[i],max(B[j],C[k]));
        if(maxx==A[i])
            i--;
        else if(maxx==B[j])
            j--;
        else if(maxx==C[k])
            k--;
    }
    return lowlim;
}
//krutikas code
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {

    int i=0;
    int j=0;
    int k=0;
    int min=INT_MAX;
    int dif;
    while(i<A.size())
    {
        int mi=(A[i]<B[j])?((A[i]<C[k])?A[i]:C[k]):((B[j]<C[k])?B[j]:C[k]);
        int ma=(A[i]>B[j])?((A[i]>C[k])?A[i]:C[k]):((B[j]>C[k])?B[j]:C[k]);
        //dif=abs(max(A[i],max(B[j],C[k]))-min(A[i],min(B[j],C[k])));
        dif=abs(ma-mi);
        if(dif<min)
           min=dif;
        if(k==C.size()-1)
        {
            k=0;
            j++;
        }
        if(j==B.size()-1)
        {
            j=0;
            i++;
        }
        else
            k++;
    }
    return min;
}

