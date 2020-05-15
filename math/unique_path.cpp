#include<iostream>
using namespace std;

int uniquepath(int A,int B)
{
    int grid[A][B];
    for(int i=0;i<B;i++)
    {
        grid[0][i]=1;
    }
    for(int i=0;i<A;i++)
    {
        grid[i][0]=1;
    }
    for(int i=1;i<A;i++)
    {
        for(int j=1;j<B;j++)
            grid[i][j]=grid[i-1][j]+grid[i][j-1];
    }
     for(int i=0;i<A;i++)
    {
        for(int j=0;j<B;j++)
            cout<<grid[i][j]<<" ";
        cout<<"\n";
    }
    return grid[A-1][B-1];
}
int main()
{
    int a=uniquepath(15,9);
    cout<<a;
}
