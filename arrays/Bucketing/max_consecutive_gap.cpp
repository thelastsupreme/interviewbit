// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

// Try to solve it in linear time/space.

// Example :

// Input : [1, 10, 5]
// Output : 5 
// Return 0 if the array contains less than 2 elements.

// You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
// You may also assume that the difference will not overflow.

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

//logic :just sort and iterate and store max when encountered for every comparison
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
