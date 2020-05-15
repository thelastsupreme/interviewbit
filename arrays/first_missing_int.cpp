#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
int firstMissingPositive(vector<int> &A) {
    int n=A.size();
    int countt=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]>0)
            countt++;
    }
    vector<bool>B(countt+1,false);
   // fill(B.begin(),B.end(),false);
    sort(A.begin(),A.end());
    B[0]=true;
    for(int i=n-countt;i<n;i++)
    {
        if(A[i]>0)
        {
            B[A[i]]=true;
        }
    }
    int i=0;
    for(i;i<countt;i++)
    {
        if(B[i]==false)
        {
            break;
        }
    }
    return(i);
}
int main()
{
    vector<int>A={10,7,-1,1,2,3,5,-23,-71};
    int n=firstMissingPositive(A);
    cout<<n;
}
