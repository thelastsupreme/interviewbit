// Given an unsorted integer array, find the first missing positive integer.

// Example:

// Given [1,2,0] return 3,

// [3,4,-1,1] return 2,

// [-8, -7, -6] returns 1

// Your algorithm should run in O(n) time and use constant space.
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
//logic i used looking back is quite lengthy
//but count number of positive elements in the array
//then sort them and iterate only for positive elements and just use a bool vector to set flags to true;
//now for the element whose flag is still false is the missing element
int firstMissingPositive(vector<int> &A) {
    int n=A.size();
    int countt=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]>0)
            countt++;  //get positive count
    }
    vector<bool>B(countt+1,false);
    sort(A.begin(),A.end()); //sort
    B[0]=true;
    for(int i=n-countt;i<n;i++)
    {
        if(A[i]>0)
        {
            B[A[i]]=true; //set flags
        }
    }
    int i=0;
    for(i;i<countt;i++)
    {
        if(B[i]==false)  //find a false flag
        {
            break;
        }
    }
    return(i); //return it
}
int main()
{
    vector<int>A={10,7,-1,1,2,3,5,-23,-71};
    int n=firstMissingPositive(A);
    cout<<n;//op 4
}
