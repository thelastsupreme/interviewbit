#include<iostream>
#include<string>
using namespace std;

int isPalindrome(string A) {
    string B;
    int n =A.size();
    for(int i=0;i<n;i++)
    {
        if((A[i]>='0'&&A[i]<='9')||(A[i]>=65&&A[i]<=90)||(A[i]>=97&&A[i]<=122)) //isalnum from cctype
            B.push_back(tolower(A[i]));
    }
    //cout<<B<<endl;
    for(int i=0;i<B.size()/2;i++)
    {
        if(B[i]!=B[B.size()-i-1])
        {
            return 0;
        }
    }
    return 1;


}

int main()
{
    int n=isPalindrome("alola");
    cout<<n;
}
