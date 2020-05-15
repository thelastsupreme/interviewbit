//prabhaths code
int Solution::cntBits(vector<int> &A) {
    long long int ans=0,n=A.size();
    long long int count;
    for(int i=0;i<31;i++){
        count=0;
        for(int j=0;j<n;j++){
            if(A[j]&(1<<i))
             count++;
        }
        ans=(ans+count*(n-count)*2);
    }
    return ans%1000000007;
}

//krutikas code
int countt(long long int A)
{
    bitset<32>b(A);
    return b.count();
}
int Solution::cntBits(vector<int> &A) {
   n=A.size();
   long long int temp=0;
    long long int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp=A[i]^A[j];
            count+=countt(temp);
        }
    }
    return count%1000000007;
}
