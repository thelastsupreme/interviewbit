
int Solution::isPalindrome(int A) {
    if(A<0)
        return 0;
    int B=A;
    long long int res=0;
    while(B)
    {
        res=res*10+B%10;
        B/=10;
    }
    if(res==A)
        return 1;
    return 0;
}
