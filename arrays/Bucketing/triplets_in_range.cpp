// Given an array of real numbers greater than zero in form of strings.
// Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
// Return 1 for true or 0 for false.

// Example:

// Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

// You should return 1

// as

// 0.6+0.7+0.4=1.7

// 1<1.7<2

// Hence, the output is 1.

// O(n) solution is expected.

// Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//logic :just calculate the sum check if it lies between 1 and 2 
//if it excceds two remove max element and go for the next one
//if it is less than one replace min amongst the three with a new element
int solve(vector<string> &A) {
    int n = A.size(), i;
    vector<float> v;
    for (i = 0; i < n; i++)
    {
        v.push_back(stof(A[i]));
    }
    float a = v[0], b = v[1], c = v[2];

    float mx = 0;
    for (i = 3; i < n; i++)
    {
        if (a + b + c < 2 && a + b + c > 1)
            return 1;
        else if (a + b + c > 2) //greater than 2 replace max with current
        {
            if (a > b && a > c)   //optimize by writing max function
                a = v[i];
            else if (b > a && b > c)
                b = v[i];
            else
                c = v[i];
        }
        else //less than 1 replace min with current
        {
            if (a < b && a < c) //optimize by writing a min function
                a = v[i];
            else if (b < a && b < c) 
                b = v[i];
            else
                c = v[i];
        }
    }
    if (a + b + c > 1 && a + b + c < 2)
        return 1;
    else
        return 0;
}

int main()
  {
      vector<string> s={"2.673662", "2.419159", "0.573816", "2.454376", "0.403605", "2.503658", "0.806191" };
      int n=solve(s);
      cout<<n;
  }

