int Solution::titleToNumber(string A) {
    int res=0;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        res+=pow(26,n-i-1)*(A.at(i)-'A'+1);
    }
    return res;
}
