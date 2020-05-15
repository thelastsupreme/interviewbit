#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}


vector<int> findPerm(const string A, int B) {
    int l=B;
    int f=1;
    vector<int>res;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='I')
            {
                res.push_back(f);
                f++;
            }
        if(A[i]=='D')
        {
            res.push_back(l);
            l--;
        }
    }
    res.push_back(f);
    return res;

}
int main()
{
    string s="IDIII";
    int n=6;
    vector<int>res=findPerm(s,n);
    print(res);
}
