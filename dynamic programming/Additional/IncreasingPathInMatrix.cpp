// Problem Description

// Given a 2D integer matrix A of size N x M.

// From A[i][j] you can move to A[i+1][j], if A[i+1][j] > A[i][j], or can move to A[i][j+1] if A[i][j+1] > A[i][j].

// The task is to find and output the longest path length if we start from (0, 0).

// NOTE:

// If there doesn't exist a path return -1.


// Problem Constraints
// 1 <= N, M <= 103

// 1 <= A[i][j] <= 108



// Input Format
// First and only argument is an 2D integer matrix A of size N x M.



// Output Format
// Return a single integer denoting the length of longest path in the matrix if no such path exists return -1.



// Example Input
// Input 1:

//  A = [  [1, 2]
//         [3, 4]
//      ]
// Input 2:

//  A = [  [1, 2, 3, 4]
//         [2, 2, 3, 4]
//         [3, 2, 3, 4]
//         [4, 5, 6, 7]
//      ]


// Example Output
// Output 1:

//  3
// Output 2:

//  7


// Example Explanation
// Explanation 1:

//  Longest path is either 1 2 4 or 1 3 4.
// Explanation 2:

//  Longest path is 1 2 3 4 5 6 7.

#include <bits/stdc++.h>
using namespace std;
void print_vect(vector<vector<int> >&input)
{
	for (int i = 0; i < input.size(); i++) {
		for(int j=0;j<input[i].size();j++)
        {
            cout << input[i][j] << ' ';
        }
        cout<<endl;
	}
    cout<<"****************"<<endl;
}

//question wasnt clear below code determines any path from origin
//but question wants to know length when u reach the bottom corner
int solve(vector<vector<int> > &A) {
    vector<vector<int>>t(A.size(),vector<int>(A[0].size(),0));
    t[0][0]=1;
    print_vect(t);
    for(int i=1;i<A.size();i++)
    {
        if(A[i][0]>A[i-1][0])
            t[i][0]=t[i-1][0]+1;
        else{
            break;
        }
    }
    for(int i=1;i<A[0].size();i++)
    {
        if(A[0][i]>A[0][i-1])
            t[0][i]=t[0][i-1]+1;
        else{
            break;
        }
    }
    print_vect(t);
    for(int i=1;i<A.size();i++)
    {
        for(int j=1;j<A[0].size();j++)
        {
            if((A[i][j]>A[i-1][j]||A[i][j]>A[i][j-1])&&t[i-1][j]!=0&&t[i][j-1]!=0)
                t[i][j]=1+max(t[i-1][j],t[i][j-1]);
        }
    }
    print_vect(t);
    int result=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            result=max(result,t[i][j]);
        }
    }
    if(result==1)
        return -1;
    return result;
}

//best solution
// int solve1(vector<vector<int> > &A) {
//     int n=A.size();
// if(n==0)
// return true;
//  int m=A[0].size();
 
//    vector<vector<bool>>dp(n,vector(m,false));
//    dp[0][0]=true;
//      for(int i=1;i<m;i++)
//      {
//           if(A[0][i]>A[0][i-1] and dp[0][i-1])
//             dp[0][i]=true;
//      }
//      for(int i=1;i<n;i++)
//      {
//          if(A[i][0]>A[i-1][0] and dp[i-1][0])
//          dp[i][0]=true;
//      }
   
//      for(int i=1;i<n;i++)
//      {
//           for(int j=1;j<m;j++)
//           {
              
//               if((A[i-1][j]<A[i][j] and dp[i-1][j])||(A[i][j-1]<A[i][j] and dp[i][j-1]))
//                 dp[i][j]=true;
//           }
//      }
     
//      if(dp[n-1][m-1])
//      return n+m-1;
//       return -1;
// }

int main()
{
    vector<vector<int>>A = {{35, 1, 70, 25, 79, 59, 63, 65},
                            {6, 46, 82, 28, 62, 92, 96, 43}};
    cout<<solve(A);
}
