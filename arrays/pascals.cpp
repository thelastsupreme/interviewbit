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
vector<vector<int> > solve(int A) {
    vector<vector<int>>res( A , vector<int> (A, 0));
    if(A==0)
    {
        vector<vector<int>>re;
        return re;
    }
    for(int i=0;i<A;i++)
    {
        res[i][0]=1;
        res[i][i]=1;
        for(int j=1;j<i;j++)
            res[i][j]=res[i-1][j-1]+res[i-1][j];

    }
    for(int i=0;i<A;i++)
        res[i].erase(res[i].begin()+i+1,res[i].end());
    return res;
}
//fastest
vector<vector<int> > Solution::generate(int A) {
    if (A == 0) { return {}; }
    vector<vector<int>> r(A);
    r[0].push_back(1);
    for (int i = 1; i < A; ++i) {
        r[i].push_back(1);
        for (int j = 1; j < i; ++j) {
            r[i].push_back(r[i-1][j] + r[i-1][j-1]);
        }
        r[i].push_back(1);
    }
    return r;
}
int main()
{
    int n=4;
    vector<vector<int>>A=solve(n);
    print(A[3]);
}
