#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> A(3);

void printt(vector<int> A)
{
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<" ";
    cout<<endl;
}
void printBinary(int n,vector<int> A)
{
    if(n<1)
    {
        reverse(A.begin(), A.end());
        printt(A);
    }
    else{
        A[n-1]=0;
        printBinary(n-1,A);
        A[n-1]=1;
        printBinary(n-1,A);
    }
}
int main()
{
    int i=3;
    vector<int> A(i);
    printBinary(i,A);
}

