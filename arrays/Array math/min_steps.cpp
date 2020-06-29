
// You are in an infinite 2D grid where you can move in any of the 8 directions

//  (x,y) to 
//     (x+1, y), 
//     (x - 1, y), 
//     (x, y+1), 
//     (x, y-1), 
//     (x-1, y-1), 
//     (x+1,y+1), 
//     (x-1,y+1), 
//     (x+1,y-1) 
// You are given a sequence of points and the order in which you need to cover the points.. Give the minimum number of steps in which you can achieve it. You start from the first point.

// NOTE: This question is intentionally left slightly vague. Clarify the question by trying out a few cases in the “See Expected Output” section.



// Input Format
// Given two integer arrays A and B, where A[i] is x coordinate and B[i] is y coordinate of ith point respectively.



// Output Format
// Return an Integer, i.e minimum number of steps.



// Example Input
// Input 1:

//  A = [0, 1, 1]
//  B = [0, 1, 2]


// Example Output
// Output 1:

//  2


// Example Explanation
// Explanation 1:

//  Given three points are: (0, 0), (1, 1) and (1, 2).
//  It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).

#include<iostream>
#include<vector>
using namespace std;

//logic: only core logic here is to remember the diagonal is the shortest path
//prabhaths code
int coverPoints(vector<int> &A, vector<int> &B) {
    int x_count=0,y_count=0;
    int diag_steps=0;
    int ans=0;
    for(int i=0;i<A.size()-1;i++)
     {
        x_count=abs(A[i]-A[i+1]); //horizontal dist
        //cout<<x_count<<" ";
        y_count=abs(B[i]-B[i+1]); //vertical dist
        //cout<<y_count<<" ";
        //diag_steps=abs(x_count-y_count);
        //cout<<diag_steps<<"\n";
        if(x_count>=y_count) //max of either is result
        ans+=(x_count);
        else
        ans+=(y_count);
     }
     return ans;

}
//krutikas code
int coverPoints_K(vector<int> &X, vector<int> &Y) {
    int t=0; int n=X.size();
    for(int i=1;i<n;i++)
    {
        int x=abs(X[i-1]-X[i]);
        int y=abs(Y[i-1]-Y[i]);
        t+=max(x,y);
    }
    return t;
}
//prakritis code
int coverPoints_P(vector<int> &A, vector<int> &B)
{
    int n=A.size(),ans=0;
    for(int i=0;i<n-1;i++){

        if(abs(A[i]-A[i+1])<=abs(B[i]-B[i+1]))
         ans+=abs(B[i]-B[i+1]);
        else
        {
            ans+=abs(A[i]-A[i+1]);
        }
    }
    return ans;
}


int main()
{
    vector<int>A={ 4, 8, -7, -5, -13, 9, -7, 8 };
    vector<int>B={ 4, -15, -10, -3, -13, 12, 8, -8 };
    cout<<coverPoints_K(A,B)<<endl;
    cout<<coverPoints(A,B);
}
