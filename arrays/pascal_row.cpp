#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
vector<int>solve(int A) {
    vector<vector<int>>res( A+1 , vector<int> (A+1, 0));
    if(A<0)
    {
        vector<int>re;
        return re;
    }

    for(int i=0;i<A+1;i++)
    {
        res[i][0]=1;
        res[i][i]=1;
        for(int j=1;j<i;j++)
            res[i][j]=res[i-1][j-1]+res[i-1][j];

    }
    for(int i=0;i<A+1;i++)
        res[i].erase(res[i].begin()+i+1,res[i].begin()+A+1);
    return res[A];
}
int main()
{
    int n=3;
    vector<int>A=solve(n);
    print(A);
}
