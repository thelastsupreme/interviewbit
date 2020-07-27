// There is a rectangle with left bottom as  (0, 0) and right up as (x, y). There are N circles such that their centers are inside the rectangle.
// Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.

// Note : We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.


// Input Format

// 1st argument given is an Integer x.
// 2nd argument given is an Integer y.
// 3rd argument given is an Integer N, number of circles.
// 4th argument given is an Integer R, radius of each circle.
// 5th argument given is an Array A of size N, where A[i] = x cordinate of ith circle
// 6th argument given is an Array B of size N, where B[i] = y cordinate of ith circle
// Output Format

// Return YES or NO depending on weather it is possible to reach cell (x,y) or not starting from (0,0).
// Constraints

// 0 <= x, y, R <= 100
// 1 <= N <= 1000
// Center of each circle would lie within the grid
// For Example

// Input:
//     x = 2
//     y = 3
//     N = 1
//     R = 1
//     A = [2]
//     B = [3]
// Output:
//     NO
   
// Explanation:
//     There is NO valid path in this case

#include <bits/stdc++.h>
using namespace std;

vector<int>rowNbr = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
vector<int>colNbr = { -1, 0, 1, -1, 1, -1, 0, 1 };

float distance(int x1, int y1, int x2, int y2) 
{ 
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0); 
}

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
bool isSafe(vector<vector<int>>&graph,int r,int c)
{
    //cout<<r<<" "<<c<<endl;
    if(r>=0&&r<graph.size()&&c>=0&&c<graph[0].size()&&graph[r][c]==0)
        return true;
    return false;
}
void DFS(vector<vector<int>>&graph,int r,int c)
{
    // cout<<r<<" "<<c<<endl;
    graph[r][c]=1;
    for (int k = 0; k < 8; ++k) {
        if (isSafe(graph, r+rowNbr[k], c+colNbr[k])) 
                DFS(graph,r+rowNbr[k], c+colNbr[k]); 
    }

}
string solve(int Row, int Col, int N, int R, vector<int> &Xcord, vector<int> &Ycord) {
    vector<vector<int>>points(Row+1,vector<int>(Col+1,0));
    // print_vect(points);
    for(int i=0;i<Row+1;i++)
    {
        for(int j=0;j<Col+1;j++)
        {
            for(int k=0;k<N;k++)
            {
                if(distance(i,j,Xcord[k],Ycord[k])<=R)
                    points[i][j]=2;
            }
        }
    }
    // print_vect(points);
    DFS(points,0,0);
    // print_vect(points);
    if(points[Row][Col]==1)
        return "YES";
    return "NO";
}
int main()
{
    vector<int>X={15, 11, 7, 31, 3, 18, 18, 12, 31};
    vector<int>Y={5, 5, 0, 29, 2, 14, 1, 30, 18 };
    cout<<solve(37,38,9,2,X,Y);
}