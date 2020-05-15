#include<iostream>
#include<vector>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

vector<int>nextPermutation(vector<int> &A) {
   int i,j,letf_l,index,temp;
    for(i=A.size()-1;i>0;i--)
    {
        if(A[i]>A[i-1])
            break;             //i returns where the descending order breaks
    }
    if(i==0)
    {
        sort(A.begin(),A.end());
        return A ;
    }
    letf_l=i-1;
    index=i;
    temp=index;
    for(i=A.size()-1;i>index;i--)
    {
        if(A[i]>A[letf_l] && A[i]<A[temp])
            temp=i;                             //for numbers between left_l and last element if any number is > left_l and less than index element that needs to come forward and sort the rest.
    }
    int t=A[temp];
    A[temp]=A[letf_l];
    A[letf_l]=t;
    letf_l++;
    sort(A.begin()+letf_l,A.end());
    return A;
}
