
//prabhaths code
int Solution::isPower(int A) {
    if(A==1||A==0) return 1;
    int p=2;
    float x=pow(A,1.0/p);
    while((int)x>1){
        //cout<<x<<endl;
        if(x-(int)x==0)
         return 1;
        p++;
        x=pow(A,1.0/p);
    }
    return 0;
}

//krutikas code
int Solution::isPower(int A)
{
    if(A==1)return 1;
    for(int i=2;i<=sqrt(A);i++)
    {
        long int n=1; // int n gives TLE error.
        while(true)
        {
            n=n*i;
            if(n==A)
            return 1;

            else if(n>A)
            break;
        }
    }
    return 0;
}


