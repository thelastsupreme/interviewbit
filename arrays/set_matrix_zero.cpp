#include<iostream>
#include<vector>
#include<algorithm>
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
void print(std::vector<bool> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

void setZeroes(vector<vector<int> > &A) {
    vector<bool>col_check(A.size(),true);
    vector<bool>row_check(A.size(),true);
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {

            if(A[i][j]==0)
            {
                col_check[j]=false;
                row_check[i]=false;
            }

        }
    }
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {

            if(row_check[i]==false||col_check[j]==false)
            {
                A[i][j]=0;
            }

        }
    }
    print_vect(A);

}
//krutikas code
void Solution::setZeroes(vector<vector<int> > &A) {

    vector<int> m(A.size());
    vector<int> col;
    int flag=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A.size();j++)
        {
            if(A[i][j]==0)
            {
                flag=1;
                col.push_back(j);
            }
        }
        if(flag)
           { A[i]=m; flag=0;}
    }
    for(int i=0;i<A.size();i++)
       for(int j=0;j<i;j++)  //limits?
           A[i][j]=A[j][i];
    for(int i=0;i<col.size();i++)
        A[col[i]]=m;

}

int main()
{
    vector<vector<int>> A={{1,1},{0,0}};
    vector<vector<int>> C={{1,0,1},{1,1,1},{1,0,1}};
    setZeroes(C);
    //print_vect(B);
}
