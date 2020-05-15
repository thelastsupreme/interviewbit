#include<iostream>
#include<math.h>
#include<cmath>
#include<climits>
using namespace std;

//prabhath code
int highestPowerof2(int n)
{
    int res = 0;
    for (int i=n; i>=1; i--)
    {
        // If i is a power of 2
        if ((i & (i-1)) == 0)
        {
            res = i;
            break;
        }
    }
    return res;
}
int divide(int A, int B) {
    long long int m=A;
    if(m<0)
        m*=-1;
   // cout<<m<<endl;
    if(B==1)
        return A;
    if(m>=INT_MAX&& abs(B)==1)
        return INT_MAX;
    int flag=1;
    if(A<0||B<0 &&(!(A<0 && B<0)))
        flag=-1;
   // cout<<flag<<endl;
    if(abs(A)==1&&abs(B)==1)
        {
          return abs(A)*flag;
        }


    int x=log2(highestPowerof2(abs(B)));
  // cout<<x<<endl;
    for(int i=0;i<x;i++)
        A=A>>1;
   // cout<<A<<endl;
    if(flag==-1)
    return A*flag;
    else
    return A;

}
//krutikas code
int Solution::divide(int A, int B) {
   long int sol=0;
   long long m=abs(A);
   int flag=1;
   if(B==-1&&A<0) return abs(A);
   if((B==1&&A<0)||(B==1&&A>0)) return A;
   if(B==-1&&A>0) return A*-1;
   if(m>=INT_MAX) return INT_MAX;
   m=A*B;
   if(m<0) flag=-1;
   while(abs(A)>=abs(B)) //this was > only , it failed case -1,1
   {
       A=abs(A)-abs(B);
       sol++;
   }
   return sol*flag;
}

//solution by interviewbit
int Solution::divide(int a, int b) {
   long long n = a, m = b;
   int sign = n < 0 ^ m < 0 ? -1 :1;
   long long q = 0;
   n = abs(n);
   m = abs(m);
   for (long long t = 0, i = 31; i >= 0; i--)
        if (t + (m << i) <= n)
            t += m << i, q |= 1LL << i;

    // assign back the sign
    if (sign < 0) q = -q;

    // check for overflow and return
    return q >= INT_MAX || q < INT_MIN ? INT_MAX : q;
}


int main()
{
    int n=divide(-2147483648,1);
    cout<<n;
}
