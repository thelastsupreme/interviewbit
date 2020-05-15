//krutikas code
int Solution::findMinXor(vector<int> &A) {

    int temp;
    int min=INT_MAX;
    sort(A.begin(),A.end());
   for(int i=0;i<A.size()-1;i++)
    {
        temp=A[i]^A[i+1];
        //cout<<temp<<endl;
        if(temp<min) min=temp;
    }
    return min;
}
//prabhaths code
int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(),A.end());
    //int val;
    int temp;
    int res=INT_MAX;
    for(int i=0;i<A.size()-1;i++)
    {
        temp=A[i]^A[i+1];
        res=min(res,temp);
    }
    return res;
}

