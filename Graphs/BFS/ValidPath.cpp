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