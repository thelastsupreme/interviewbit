// You are given an integer N. You have to find smallest multiple of N which consists of digits 0 and 1 only. Since this multiple could be large, return it in form of a string.

// Note:

// Returned string should not contain leading zeroes.
// For example,

// For N = 55, 110 is smallest multiple consisting of digits 0 and 1.
// For N = 2, 10 is the answer.

#include <bits/stdc++.h>
using namespace std;
  
// method returns smallest multiple which has 
// binary digits 
string getMinimumMultipleOfBinaryDigit(int N) 
{ 
    queue<string> q; 
    set<int> visit; 
  
    string t = "1"; 
  
    //  In starting push 1 into our queue 
    q.push(t); 
    //  loop untill queue is not empty 
    while (!q.empty()) 
    { 
        // Take the front number from queue. 
        t = q.front();
        q.pop(); 

        // Find remainder of t with respect to N. 
        int rem = stoi(t)%N; 
        // if remainder is 0 then we have 
        // found our solution 
        if (rem== 0) 
            return t; 
        // If this remainder is not previously seen, 
        // then push t0 and t1 in our queue 
        else if(visit.find(rem) == visit.end()) 
        { 
            visit.insert(rem); 
            q.push(t + "0"); 
            q.push(t + "1"); 
        } 
    } 
} 

// use mod function if stoi not accepted
// int mod(string t, int N) 
// { 
//     int r = 0; 
//     for (int i = 0; i < t.length(); i++) 
//     { 
//         r = r * 10 + (t[i] - '0'); 
//         r %= N; 
//     } 
//     return r; 
// } 
//  Driver code to test above methods 
int main() 
{ 
    int N = 12; 
    cout << getMinimumMultipleOfBinaryDigit(N); 
    return 0; 
} 
