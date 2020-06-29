// Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.

// If such arrangement is not possible, it must be rearranged as the lowest possible order i.e., sorted in an ascending order.

// Note:

// 1. The replacement must be in-place, do **not** allocate extra memory.
// 2. DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use of Library functions will disqualify your submission retroactively and will give you penalty points.
// Input Format:

// The first and the only argument of input has an array of integers, A.
// Output Format:

// Return an array of integers, representing the next permutation of the given array.
// Constraints:

// 1 <= N <= 5e5
// 1 <= A[i] <= 1e9
// Examples:

// Input 1:
//     A = [1, 2, 3]

// Output 1:
//     [1, 3, 2]

// Input 2:
//     A = [3, 2, 1]

// Output 2:
//     [1, 2, 3]

// Input 3:
//     A = [1, 1, 5]

// Output 3:
//     [1, 5, 1]

// Input 4:
//     A = [20, 50, 113]

// Output 4:
//     [20, 113, 50]


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
        //for numbers between left_l and last element if any number is > left_l and less than index element
        //that needs to come forward and sort the rest.
        if(A[i]>A[letf_l] && A[i]<A[temp])
            temp=i;      
    }
    int t=A[temp];
    A[temp]=A[letf_l];
    A[letf_l]=t;
    letf_l++;
    sort(A.begin()+letf_l,A.end());
    return A;
}
