// You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.

// Your target is to go from top left corner to the bottom right corner of the matrix.

// But there are some restrictions while moving along the matrix:

// If you follow what is written in the cell then you can move freely.
// But if you don't follow what is written in the cell then you have to pay 1 unit of cost.
// Like: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost.

// So your task is to find the minimum cost to go from top-left corner to the bottom-right corner.



// Problem Constraints
// 1 <= A,B <= 103
// C[i][j] can be either U,R,L or D.


// Input Format
// First Argument represents a integer A (number of rows).
// Second Argument represents a integer B (number of columns).
// Third Argument represents a string array C which contains A strings each of length B.


// Output Format
// Return an integer denoting the minimum cost to travel from top-left corner to bottom-right corner.



// Example Input
// Input:1

//  A = 3
//  B = 3
//  C = ["RRR","DDD","UUU"]
// Input:2

//  A = 1
//  B = 4
//  C = ["LLLL"]


// Example Output
// Output-1 :

//  1
// Output-2 :

//  3


// Example Explanation*
// Explanation for Input-1:

//  Matrix looks like: RRR
//                     DDD
//                     UUU
//  We go right two times and down two times.
//  So from top-right cell we are going down though right is given so this incurs a cost of 1.
// Explanation for Input-2:

//  Matrix looks like: LLLL
//  We go right three times.

#include <bits/stdc++.h>
using namespace std;

//best solution from ib
#define tp tuple<int,int,int>

bool isSafe(int i,int j,int upx,int upy) //function to stay in grid
{
    return (i>=0)&&(i<upx)&&(j>=0)&&(j<upy);
}

int solve(int A, int B, vector<string> &C) {
    deque<tp> q;
    vector<vector<bool>> visited(A,vector<bool> (B,false));
    q.push_front({0,0,0});              //start from origin
    unordered_map<char,pair<int,int>> steps;
    steps.insert({'U',make_pair(-1,0)}); //map for directions
    steps.insert({'D',make_pair(1,0)});
    steps.insert({'L',make_pair(0,-1)});
    steps.insert({'R',make_pair(0,1)});
    while(!q.empty())
    {
        auto cost=get<0>(q.front());
        int i=get<1>(q.front());
        int j=get<2>(q.front());
        q.pop_front();
        visited[i][j]=true;
        if(i==A-1&&j==B-1) return cost;
        for(auto x : steps)       //for each direction explore option and store the cost
        {
            int n_x=i+x.second.first,n_y=j+x.second.second;  
            if(isSafe(n_x,n_y,A,B)&&!visited[n_x][n_y])
            {
                if(C[i][j]==x.first) //taking the path as char
                    q.push_front({cost,n_x,n_y});
                else 
                    q.push_back({cost+1,n_x,n_y});
            }
        }
    }
    return -1;
}

int main()
{

}