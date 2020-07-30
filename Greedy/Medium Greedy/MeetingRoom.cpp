// Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

// Where:

// A[i][0] = start time of the ith meeting.
// A[i][1] = end time of the ith meeting.
// Find the minimum number of conference rooms required so that all meetings can be done.



// Problem Constraints
// 1 <= N <= 10

// 0 <= A[i][0] < A[i][1] <= 2 * 109



// Input Format
// The only argument given is the matrix A.



// Output Format
// Return the minimum number of conference rooms required so that all meetings can be done.



// Example Input
// Input 1:

//  A = [      [0, 30]
//             [5, 10]
//             [15, 20]
//      ]

// Input 2:

//  A =  [     [1, 18]
//             [18, 23]
//             [15, 29]
//             [4, 15]
//             [2, 11]
//             [5, 13]
//       ]


// Example Output
// Output 1:

//  2
// Output 2:

//  4


// Example Explanation
// Explanation 1:

//  Meeting one can be done in conference room 1 form 0 - 30.
//  Meeting two can be done in conference room 2 form 5 - 10.
//  Meeting one can be done in conference room 2 form 15 - 20 as it is free in this interval.
// Explanation 2:

//  Meeting one can be done in conference room 1 from 1 - 18.
//  Meeting five can be done in conference room 2 from 2 - 11.
//  Meeting four can be done in conference room 3 from 4 - 15.
//  Meeting six can be done in conference room 4 from 5 - 13.
//  Meeting three can be done in conference room 2 from 15 - 29 as it is free in this interval.
//  Meeting two can be done in conference room 4 from 18 - 23 as it is free in this interval.

#include <bits/stdc++.h>
using namespace std;



//my method
int solve(vector<vector<int>>&A)
{
    vector<pair<int,int>>v;
    for(int i=0;i<A.size();i++)
    {
        v.push_back(make_pair(A[i][0],1));
        v.push_back(make_pair(A[i][1],-1));
    }
    sort(v.begin(),v.end());
    int res=INT_MIN;
    int count=0;
    for(int i=0;i<2*A.size();i++){
        count+=v[i].second;
        res=max(res,count);
    }
    return res;
}

//another interesting method is using a priority queue

bool comp(vector<int> A, vector<int> B)
{
    return A[0] < B[0];
}

int solve_1(vector<vector<int>> &A)
{
    sort(A.begin(), A.end(), comp);
    int ans = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(A[0][1]); //push the end time
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i][0] >= pq.top()) //if start time is greater then just remove it from queue
        {
            pq.pop();
        }
        else
        {
            ans++;      //if end time less than start time increment count
        }
        pq.push(A[i][1]); //and push its end time
    }
    return ans;
}