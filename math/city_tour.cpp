#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

int fact(int k){
    if(k==0)
    return 1;
    else return ((k*fact(k-1)));

}

int solve(int a, vector<int> &b) {
    int n =b.size();
    sort(b.begin(),b.end());
    int y=a-n;
        if(y==0)
    return 0;
    int ans=fact(y);
    int q=fact(b[0]-1);
    for(int i=0;i<n-1;i++)
        {
            int u=b[i+1]-b[i]-1;
            ans=(ans*pow(2,u-1));
            q=(q*fact(u));
        }
    q=(q*fact(a-b[n-1]));
    ans=(ans*q);
    return ans;
}
int main()
{
    vector<int>B={2,4};
    int n=solve(5,B);
    cout<<n;
}

