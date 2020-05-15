#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<limits.h>
using namespace std;
void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
int maxSpecialProduct(vector<int> &A) {
    int n=A.size();
    vector<int>left;
    vector<int>right;
    int l=0,r=INT_MAX;
    int max_s=0;
    for(int index=0;index<n;index++)
{
       cout<<"index :"<<index<<"\n";
      for(int i=0;i<n;i++)
        {
        if(i<index)
            left.push_back(A[i]);
        else if(i>index)
            right.push_back(A[i]);

        }
        print(left);
         cout<<endl;
        print(right);
        cout<<endl;
        for(int j=0;j<left.size();j++)
            {
                if(left[j]>A[index])
                    l=max(l,j);
            }

        for(int j=right.size()-1;j>=0;j--)
            {
                if(right[j]>A[index])
                    r=min(r,j);
                   // cout<<r<<endl;
            }


        int l_size=left.size();
        if(r!=INT_MAX)
            r=r+l_size+1;
        else
            r=0;
        if(right.size()==0)
            r=0;
        max_s=max(max_s,l*r);
       cout<<"l :"<<l<<endl;
       cout<<"r :"<<r<<endl;
       l=0;
       r=INT_MAX;
        left.erase(left.begin(),left.end());
        right.erase(right.begin(),right.end());
}
    return max_s%(1000000007);
}
int main()
{
    vector<int>A={7,5,7,9,8,7};
    int n=maxSpecialProduct(A);
    cout<<n;
}
