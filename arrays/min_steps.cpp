#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

//prabhaths code
int coverPoints(vector<int> &A, vector<int> &B) {
    int x_count=0,y_count=0;
    int diag_steps=0;
    int ans=0;
    for(int i=0;i<A.size()-1;i++)
     {
        x_count=abs(A[i]-A[i+1]);
        //cout<<x_count<<" ";
        y_count=abs(B[i]-B[i+1]);
        //cout<<y_count<<" ";
        //diag_steps=abs(x_count-y_count);
        //cout<<diag_steps<<"\n";
        if(x_count>=y_count)
        ans+=(x_count);
        else
        ans+=(y_count);
     }
     return ans;

}
//krutikas code
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int t=0; int n=X.size();
    for(int i=1;i<n;i++)
    {
        int x=abs(X[i-1]-X[i]);
        int y=abs(Y[i-1]-Y[i]);
        t+=max(x,y);
    }
    return t;
}
//prakritis code
int Solution::coverPoints(vector<int> &A, vector<int> &B)
{
    int n=A.size(),ans=0;
    for(int i=0;i<n-1;i++){

        if(abs(A[i]-A[i+1])<=abs(B[i]-B[i+1]))
         ans+=abs(B[i]-B[i+1]);
        else
        {
            ans+=abs(A[i]-A[i+1]);
        }
    }
    return ans;
}


int main()
{
    vector<int>A={ 4, 8, -7, -5, -13, 9, -7, 8 };
    vector<int>B={ 4, -15, -10, -3, -13, 12, 8, -8 };
    cout<<coverPoints(A,B);
}
