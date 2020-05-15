//prabhaths code
int Solution::numSetBits(unsigned int A) {
    int count=0;
    for(int i=0;i<32;i++)
        if(A&(1<<i))
            count++;
    return count;
}

int Solution::numSetBits(unsigned int A) {
    int ans=0;
    while(A!=0)
    {
        A=A&(A-1);
        ans++;
    }
    return ans;
}
