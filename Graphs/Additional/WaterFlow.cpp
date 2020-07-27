// Problem Description

// Given an N x M matrix A of non-negative integers representing the height of each unit cell in a continent, the "Blue lake" touches the left and top edges of the matrix and the "Red lake" touches the right and bottom edges.

// Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

// Find the number of cells from where water can flow to both the Blue and Red lake.



// Problem Constraints
// 1 <= M, N <= 1000

// 1 <= A[i][j] <= 109



// Input Format
// First and only argument is a 2D matrix A.



// Output Format
// Return an integer denoting the number of cells from where water can flow to both the Blue and Red lake.



// Example Input
// Input 1:

//  A = [
//        [1, 2, 2, 3, 5]
//        [3, 2, 3, 4, 4]
//        [2, 4, 5, 3, 1]
//        [6, 7, 1, 4, 5]
//        [5, 1, 1, 2, 4]
//      ]
// Input 2:

//  A = [
//        [2, 2]
//        [2, 2]
//      ]


// Example Output
// Output 1:

//  7
// Output 2:

//  4


// Example Explanation
// Explanation 1:

//  Blue Lake ~   ~   ~   ~   ~ 
//         ~  1   2   2   3  (5) *
//         ~  3   2   3  (4) (4) *
//         ~  2   4  (5)  3   1  *
//         ~ (6) (7)  1   4   5  *
//         ~ (5)  1   1   2   4  *
//            *   *   *   *   * Red Lake
//  Water can flow to both lakes from the cells denoted in parentheses.

// Explanation 2:

//  Water can flow from all cells.
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
}
bool check(int x, int y, int n, int m){
    if(x >= 0 && x < n && y >= 0 && y < m){
        return true;
    }
    return false;
}

int solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    int ans = 0;
    vector<vector<int>>blue(n,vector<int>(m,0));
    vector<vector<int>>red(n,vector<int>(m,0));
    queue<pair<int,int>> q;
    // All the co-ordinates which touches blue lake on left edge
    for(int i = 1; i < n; i++){
        q.push({i,0});
        blue[i][0] = 1;
    }
    // All the co-ordinates which touches blue lake on top edge
    for(int i = 0; i < m; i++){
        q.push({0,i});
        blue[0][i] = 1;
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};


    while(!q.empty()){
        pair<int,int> idx = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int x = idx.first + dx[i], y = idx.second + dy[i];
            if(check(x, y, n, m) && blue[x][y] == 0 && A[x][y] >= A[idx.first][idx.second]){
                  q.push({x,y});
                  blue[x][y]=1;  //mark the cells that are capable to act as source
            }
        }
    }
    // All the co-ordinates which touches red lake on right edge
    for(int i = 0; i < n; i++){
        q.push({i,m-1});
        red[i][m-1] =1;
    }
    // All the co-ordinates which touches red lake on bottom edge
    for(int i = m-2; i >= 0; i--){
        q.push({n-1,i});
        red[n-1][i] =1;
    }

    while(!q.empty()){
        pair<int,int> idx = q.front();
        if(red[idx.first][idx.second] == 1 && blue[idx.first][idx.second] == 1){ //if they are source for both add to result
            ans += 1;
        }
        q.pop();
        for(int i = 0; i < 4; i++){
            int x = idx.first + dx[i], y = idx.second + dy[i];
            if(check(x, y, n, m) && red[x][y] == 0 && A[x][y] >= A[idx.first][idx.second]){
                  q.push({x,y});
                  red[x][y]=1; //mark the cells that are capable to act as source
            }
        }
    }
    print_vect(blue);
    cout<<"********************"<<endl;
    print_vect(red);
    return ans;
}

int main()
{
    vector<vector<int>> A = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4},
    };
    cout<<solve(A);
}