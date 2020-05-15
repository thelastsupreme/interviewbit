#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//convert int to char : +'0'
//convert char to int : -'0'
string addBinary(string A, string B) {
    string ans="";
   int i=A.length()-1,j=B.length()-1,a=0,b=0,sum=0,carry=0;
   while(i>=0 || j>=0){
        i>=0?a=A[i]-'0':a=0; //if value present take it else assume 0
        j>=0?b=B[j]-'0':b=0;
    sum=(a+b+carry);
    ans.push_back(sum%2+'0');
    carry=sum/2; //carry is 1 when sum is 2 and 3

    i--,j--;
   }
   if(carry)
   ans.push_back('1');

   reverse(ans.begin(),ans.end());

return ans;
}

/*string addBinary(string A, string B) {
    string res="";
    int m=A.size();
    int n=B.size();

    //int res[max(m,n)+1];
    //cout<<"A: "<<A<<endl;
    //cout<<"B: "<<B<<endl;
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    if(m<n)
    {
        for(int i=0;i<n-m;i++)
            A.push_back('0');
    }
    else
    {
        for(int i=0;i<m-n;i++)
            B.push_back('0');
    }
    cout<<"A: "<<A<<endl;
    cout<<"B: "<<B<<endl;
    int c=0;
    for(int i=0;i<max(m,n);i++)
        {
            if(A[i]=='0' && B[i]=='0' && c==0)
               {
                   res.push_back('0');
                   c=0;
               }
            if(A[i]=='0' && B[i]=='1' && c==0)
               {
                   res.push_back('1');
                   c=0;
               }
            if(A[i]=='1' && B[i]=='0' && c==0)
               {
                   res.push_back('1');
                   c=0;
               }
            if(A[i]=='0' && B[i]=='0' && c==1)
               {
                   res.push_back('1');
                   c=0;
               }
            if(A[i]=='1' && B[i]=='1' && c==0)
               {
                   res.push_back('0');
                   c=1;
               }
            if(A[i]=='1' && B[i]=='1' && c==1)
               {
                   res.push_back('1');
                   c=1;
               }
            if(A[i]=='0' && B[i]=='1' && c==1)
               {
                   res.push_back('0');
                   c=1;
               }
            if(A[i]=='1' && B[i]=='0' && c==1)
               {
                   res.push_back('0');
                   c=0;
               }
        }
   // if(c==1)
   // res.push_back('1');
    //cout<<res<<endl;
    reverse(res.begin(),res.end());
    return res;
}
*/
//prakritis code
string Solution::addBinary(string A, string B)
{
    string r;
    int s=0;
    int i=A.size()-1 , j =B.size()-1;
    while(i>=0 || j>=0 || s==1)
    {
        if(i>=0)
        {
            s+=A[i]-'0';
        }
        if(j>=0)
        {
            s+=B[j]-'0';
        }
        r = char(s % 2 + '0') + r;
        s /= 2;
        i--; j--;
    }
    return r;
}

int main()
{
 string a = "1010110111001101101000";
string b= "1000011011000000111100110";

 string res=addBinary(a,b);
 cout<<res;
}
