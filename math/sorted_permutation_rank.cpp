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
int factorial(int n)
{
    // single line to find factorial
    return (n==1 || n==0) ? 1: n * factorial(n - 1);
}
int findRank(string A) {
    int rankk=0;
    int l=A.size();
    for(int i=0;i<l-1;i++)
    {
        int count=0;
        for(int j=i+1;j<l;j++)
        {
            if(A[j]<A[i])
                count++;
        }
        rankk+=(factorial(l-i-1)*count)%1000003;

    }
    return (rankk+1)%1000003;
}
/*int findRank(string A) {
    int rankk=0;
    int i=0;
    string B=A;
    sort(B.begin(),B.end());
    if(A==B)
        return 1;
    for(i=A.size()-1;i>0;i--)
    {
        if(A[i]<A[i-1])
            break;             //i returns where the descending order breaks
    }
   // cout<<"i : "<<i<<endl;
    int len=A.size();
    for(int j=0;j<i;j++)
    {
        for(int k=0;k<A.size();k++)
        {
            if(A[j]==B[k])
                rankk+=(j+1)*(len-k)+1;
        }
    }
    return rankk;
}
*/

int main()
{
    int n=findRank("aquertw");
    cout<<n;
}
