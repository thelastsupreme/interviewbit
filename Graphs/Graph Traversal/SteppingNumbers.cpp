// Problem Description

// Given A and B you have to find all stepping numbers in range A to B.

// The stepping number:

// A number is called as a stepping number if the adjacent digits have a difference of 1.

// e.g. 123 is stepping number, but 358 is not a stepping number



// Input Format
// First argument is an integer A.

// Second argument is an integer B.



// Output Format
// Return a integer array sorted in ascending order denoting the stepping numbers between A and B.



// Example Input
// Input 1:

//  A = 10
//  B = 20


// Example Output
// Output 1:

//  [10, 12]


// Example Explanation
// Explanation 1:

//  All stepping numbers are 10 , 12 
#include <bits/stdc++.h>
using namespace std;


vector<int> stepnum(int A, int B) {
    vector<int> ans;
    if(A <= 0) ans.push_back(0);

    queue<int> nums({1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    while(nums.front() <= B){
        int i = nums.front();
        nums.pop();
        if(i >= A) ans.push_back(i);
        
        int lastd = i%10;
        if(lastd>0) nums.push(i*10+(lastd-1));
        if(lastd<9) nums.push(i*10+(lastd+1));
    }
    
    return ans;
}