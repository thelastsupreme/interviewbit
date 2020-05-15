//prakritis code
int Solution::findRank(string A) {
    int i=0,j,c,ans=0;
    vector<int> r;
    while(A[i]!='\0')
    {
        j=i;
        c=0;
        while(A[j]!='\0')
        {
            if(A[i]>A[j])
                c++;
            j++;
        }
        r.push_back(c);
        i++;
    }
    c=0;
    i=r.size()-1;
    j=0;
    while(i>=0)
    {
        ans+=r[i]*factorial(j);
        ans=ans%1000003;
        j++;
        i--;
    }
    ans=ans+1;
    return ans;
}
//prabhaths code
#define mod 1000003;

int fact(int n)
{
        if(n==0) return 1 ; else return (n*fact(n-1)) %mod;
}

int Solution::findRank(string A) {
    string s=A ;
    //cin>>s;
    int ans =0;
    int n=s.length();
    for(int i=0;i<n-1;i++)
        {
            int c=0;
            for(int j=i+1;j<n;j++)
                {
                    if(s[j]<s[i])
                        c++;
                }
            ans+=( (c*fact(n-i-1)) )%mod;
            //cout << c <<" "<<ans<< endl;
         }
        return (ans+1 )%mod;
        //cout << ans+1 ;
}
