//Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.

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

//editorial solution best approach

//logic:only important factor here is to know that the index where this change happens occurs where the element is smaller than its next
//cause obviously there u will have an opportunity to bring the greater element forward
void nextPermutation(vector<int> &A) {

    int i, j; 
    int len=A.size();
    for (i = len - 2; i >= 0; i--) //start from behind and get a point where A[i]<A[i+1]
        if (A[i] < A[i + 1])
            break;

    if (i == -1) //if i is start of the array just reverse and return
    {
        reverse(A.begin(), A.end());
        return;
    }

    for (j = len - 1; j > i; j--) //iterate till the index found from behind
        if (A[j] > A[i])      //the first element greater than element is index is found
            break;

    swap(A[i], A[j]);     //exchange their positions
    reverse(A.begin() + i + 1, A.end());     //now reverse everything after the index till the end cause those elements get a fresh start
    return;
}

int main(){
    vector<int>A={2,1,3,5,4};
    nextPermutation(A);
    print(A);
}
