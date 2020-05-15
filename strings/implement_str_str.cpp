#include<iostream>
#include<string>
using namespace std;

int strStr(const string A, const string B) {

    if(A.size()==0||B.size()==0) return -1;int flag=2;
    if(B.size()>A.size()) return -1;
    for(int i=0;i<A.size();i++)
    {
        cout<<"i :"<<i<<endl;
        if(A[i]==B[0])
        {
            for(int j=1;j<B.size()-1;j++)
            {
                if(A[i+j]==B[j]) {flag=1;continue;}
                else
                { flag=0; break;}
            }
        }
        if(flag==1) return i;
    }
    return -1;
}


//best approach
/*int Solution::strStr(const string A, const string B) {
    if(A.size()==0||B.size()==0)
        return -1;
    int n=B.size();
    string temp="";
    for(int i=0;i<A.size();i++)
    {
        temp=A.substr(i,n);
        if(temp==B)
        return i;
    }
    return -1;
}
*/
int main()
{
    int n=strStr("hello","lo");
    cout<<n;
}
