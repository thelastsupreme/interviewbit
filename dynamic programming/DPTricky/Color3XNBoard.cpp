// Given a 3 x A board, find the number of ways to color it using at most 4 colors such that no 2 adjacent boxes have same color.

// Diagonal neighbors are not treated as adjacent boxes.

// Return the ways modulo 109 + 7 as the answer grows quickly.

// Input Format:

// The first and the only argument contains an integer, A.
// Output Format:

// Return an integer representing the number of ways to color the board.
// Constraints:

// 1 <= A < 100000
// Examples:

// Input 1:
//     A = 1

// Output 1:
//     36

// Input 2:
//     A = 2

// Output 2:
//     588
#include <bits/stdc++.h>
using namespace std;


int solve(int A) 
{ 
      
    // When we to fill single column 
    long int color3 = 24;  //filling one col with 3 colors not adjacent is 4C3*3!
    long int color2 = 12;  //filling one col with 2 colors not adjacent is 4C2*2!
    long int temp = 0; 
      
    for (int i = 2; i <= A; i++)  
    { 
        temp = color3; 
        color3 = (11 * color3 + 10 * 
              color2 ) % 1000000007; 
                
        color2 = ( 5 * temp + 7 * 
              color2 ) % 1000000007; 
    } 
      
    long num = (color3 + color2) 
                       % 1000000007; 
                         
    return (int)num; 
}