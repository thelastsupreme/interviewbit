#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
        cout << input.at(i) << ' ';
	}
}

int trap(const vector<int> &A) {
    vector<int>l(A.size());
    vector<int>r(A.size());
    int ans=0;
    l[0]=A[0];
    r[A.size()-1]=A[A.size()-1];
    for(int i=1;i<A.size();i++)
    {
        l[i]=max(l[i-1],A[i]);
    }
    for(int i=A.size()-2;i>=0;i--)
    {
        r[i]=max(r[i+1],A[i]);
    }
    cout<<"l[ ] : ";
    print(l);
    cout<<endl;
    cout<<"r[ ] : ";
    print(r);
    cout<<endl;
    for(int i=0;i<A.size();i++)
    {
        ans+=(min(l[i],r[i])-A[i]);
    }
    return ans;

}
int main()
{
    vector<int>A={1,4,2,4,3,3,2,1};
    int res=trap(A);
    cout<<res;
}