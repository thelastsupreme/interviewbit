// Given an integer array A, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p.



// Input Format
// First and only argument is an integer array A.



// Output Format
// Return 1 if any such integer p is found else return -1.



// Example Input
// Input 1:

//  A = [3, 2, 1, 3]
// Input 2:

//  A = [1, 1, 3, 3]


// Example Output
// Output 1:

//  1
// Output 2:

//  -1


// Example Explanation
// Explanation 1:

//  For integer 2, there are 2 greater elements in the array. So, return 1.
// Explanation 2:

//  There is no such integer exists.

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
//Initial idea
/*int Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<int>count(n,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            {
                if(A[j]>A[i])
                count[i]++;
            }
    }
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(count[i]==A[i])
            {
                flag=1;
                break;
            }

    }
    if(flag==1)
        return 1;
    else
        return -1;
}
*/
// cannot be used cause duplicates add a value too
// int solve(vector<int> &A) {
//     int n=A.size();
//     //cout<<n;
//     sort(A.begin(),A.end());
//     A.erase(unique(A.begin(), A.end()),A.end());
//     print(A);
//     int m=A.size();
//    for(int i=0;i<m;i++)
//    {
//        if(A[i]==m-1-i)
//         return 1;
//    }
//    return -1;
// }


//final logic
int solve(vector<int> &A) {
    int n=A.size();
    vector<int>count(n,0);
    sort(A.begin(),A.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] == A[i + 1]) //just iterate over if equal cause we need strictly greater than
            continue;

        if (A[i] == n - i - 1) //it means the # of numbers to the right of the element is equal to the element
            return 1;
    }
    if (A[n - 1] == 0)
        return 1;
    return -1;
}

int main()
{
    vector<int> A={1, 2, 7, 0, 9, 3, 6, 0, 6 };
    int B=solve(A);
    cout<<B<<endl;
}
