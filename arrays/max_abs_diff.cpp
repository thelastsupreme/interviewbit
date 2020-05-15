
int Solution::maxArr(vector<int> &A) {
    int best=0,max_feq=INT_MIN,max_seq=INT_MIN,min_feq=INT_MAX,min_seq=INT_MAX;
    for(int i=0;i<A.size();i++)
        {
            max_feq=max(max_feq,A[i]+i); //feq =(A[i]+i)-(A[j]+j)
            min_feq=min(min_feq,A[i]+i);
            max_seq=max(max_seq,A[i]-i); //seq =(A[i]-i)-(A[j]-j)
            min_seq=min(min_seq,A[i]-i);

        }
    best=max(max_feq-min_feq,max_seq-min_seq);
    return best;
}
