#include<iostream>
#include<string>
using namespace std;

int solve(string A) {
    int n=A.size();
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' ||  A[i] == 'o' || A[i]== 'u' || A[i] == 'A' ||  A[i]== 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
        res+=n-i;
    }
    return res%10003;
}



int main()
{
    int n=solve("uasirfdgadshgda");
    cout<<n;
}

