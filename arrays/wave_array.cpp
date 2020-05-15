#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
//prabhaths code
vector<int> wave(vector<int> &A) {
    int n=A.size();
    sort(A.begin(),A.end());
    if(n%2==0)
    {
        for(int i=0;i<n;i+=2)
        swap(A[i],A[i+1]);
    }
    else{
        for(int i=0;i<n-2;i+=2)
        swap(A[i],A[i+1]);
    }
    return A;
}
//krutikas code
vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(),A.end());int temp;
    for(int i=0;i<A.size();i+=2)
    {
        if(i+1==A.size())
         continue;

        temp=A[i];
        A[i]=A[i+1];
        A[i+1]=temp;
    }

   return A;
}
//prakritis code
vector<int> Solution::wave(vector<int> &A) {
        sort(A.begin(),A.end());
    for(int i=0;i<A.size();i+=2)
    {
        if(A.size()==i+1)
        {
            continue;
        }
        swap(A[i],A[i+1]);
    }
    return A;
}


int main()
{
    vector<int> A={6,17,15,13,1};
    vector<int>B=wave(A);
    print(B);
}
