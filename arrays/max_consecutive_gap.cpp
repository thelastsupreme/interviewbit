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


int maximumGap( const vector<int> &A) {
    int n=A.size();
    vector<int>B=A;
    int max_d=0;
    if(n<2)
        return 0;
    if(n==2)
        return abs(A[0]-A[1]);
    else
    {
        sort(B.begin(), B.end());
        for(int i=0;i<n-1;i++)
        {
           max_d=max(abs(B[i]-B[i+1]),max_d);
        }
    }
    return max_d;
}




int main()
{
    vector<int>A={1,10,5};
    int m=maximumGap(A);
    cout<<m;
}
