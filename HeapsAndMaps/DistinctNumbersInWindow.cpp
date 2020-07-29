// You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.

// Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.

// NOTE: if B > N, return an empty array.



// Input Format
// First argument is an integer array A
// Second argument is an integer B.



// Output Format
// Return an integer array.



// Example Input
// Input 1:

//  A = [1, 2, 1, 3, 4, 3]
//  B = 3
// Input 2:

//  A = [1, 1, 2, 2]
//  B = 1


// Example Output
// Output 1:

//  [2, 3, 3, 2]
// Output 2:

//  [1, 1, 1, 1]


// Example Explanation
// Explanation 1:

//  A=[1, 2, 1, 3, 4, 3] and B = 3
//  All windows of size B are
//  [1, 2, 1]
//  [2, 1, 3]
//  [1, 3, 4]
//  [3, 4, 3]
//  So, we return an array [2, 3, 3, 2].
// Explanation 2:

//  Window size is 1, so the output array is [1, 1, 1, 1].
#include <bits/stdc++.h>
using namespace std;

vector<int> dNums(vector<int> &A, int B)
{

    vector<int> v;
    int i, prev;
    map<int, int> m;

    for (i = 0; i < B; i++) //make a map of for B elements
        m[A[i]]++;

    prev = 0;
    v.push_back(m.size()); //store unique size

    for (; i < A.size(); i++)
    {
        m[A[prev]]--;  //as window moves decrease value of the left most element from map

        if (m[A[prev]] == 0) //if it is 0 then remove it completely from map
            m.erase(A[prev]);

        m[A[i]]++;    //add new element to map
        prev++;       //move the window
        v.push_back(m.size());//push size of map
    }

    return v;
}