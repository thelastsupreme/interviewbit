//prabhaths code
#include<iostream>
#include<vector>
using namespace std;

void print(std::vector<string> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) <<endl;
	}
}
bool placeable(vector<string>&temp,int row,int col,int A)
{
    for(int i=0;i<row;i++)
    {
        if(temp[i][col]=='Q')    //check if the col already has a Q
            return false;
    }
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)  //check if the left diagonal has a Q
    {
        if(temp[i][j]=='Q')
            return false;
    }
    for(int i=row,j=col;i>=0&&j<A;i--,j++) //check if the right diagonal has a Q
    {
        if(temp[i][j]=='Q')
            return false;
    }
    return true;
}
void queens_recf(int A,int row,vector<string>&temp,vector<vector<string>>&res)
{
    if(row==A)
    {
        res.push_back(temp);
    }
    for(int col=0;col<A;col++)
    {
        if(placeable(temp,row,col,A))
        {
            temp[row][col]='Q';
            queens_recf(A,row+1,temp,res);
            temp[row][col]='.';
        }
    }
}
vector<vector<string> >solveNQueens(int A) {
    vector<vector<string>>res;
    if(A==2||A==3)

        return res;
    string a(A,'.');
    vector<string>temp(A,a);
    queens_recf(A,0,temp,res);
    return res;

}
int main()
{
    int n;
    cout<<"enter the grid size: "<<endl;
    cin>>n;
    vector<vector<string>>a=solveNQueens(n);
    for(int i=0;i<a.size();i++)
    {
        print(a[i]);
        cout<<endl;
    }
}

