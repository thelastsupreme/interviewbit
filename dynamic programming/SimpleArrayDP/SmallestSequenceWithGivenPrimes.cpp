// Problem Description

// GIven three prime numbers A, B and C and an integer D.

// You need to find the first(smallest) D integers which only have A, B, C or a combination of them as their prime factors.



// Input Format
// First argument is an integer A.

// Second argument is an integer B.

// Third argument is an integer C.

// Fourth argument is an integer D.



// Output Format
// Return an array of size D denoting the first smallest D integers which only have A, B, C or a combination of them as their prime factors.

// NOTE: You need to return the array sorted in ascending order.



// Example Input
// Input 1:

//  A = 2
//  B = 3
//  C = 5
//  D = 5


// Example Output
// Output 1:

//  [2, 3, 4, 5, 6]


// Example Explanation
// Explanation 1:

//  4 = A * A i.e ( 2 * 2 ) 
//  6 = A * B i.e ( 2 * 3 )
#include <bits/stdc++.h>
using namespace std;

vector<int>solve(int A, int B, int C, int D)
{
    set<int> s;
    s.insert(A);
    s.insert(B);
    s.insert(C);
    vector<int> arr;
    if (D == 0)
        return arr;
    while (!s.empty())
    {
        int a = *(s.begin()); //use asterik to extract element
        s.erase(s.begin());
        arr.push_back(a);
        if (arr.size() == D)
            break;
        s.insert(a * A);
        s.insert(a * B);
        s.insert(a * C);
    }
    return arr;
}