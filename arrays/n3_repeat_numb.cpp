#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
//using bool only cause of memory constraint.
int repeatedNumber( vector<int> &B) {
    int n=B.size();
    //vector<int>B=A;
    int i=0;
    while(B.size()>=6&&i<n)
    {
        if(B[i]!=B[i+1]&&B[i+1]!=B[i+2]&&B[i]!=B[i+2])
        {
          B.erase(B.begin()+i,B.begin()+3+i);
          i=0;
        }
        else i++;
    }
    if(B.size()==n)
        return -1;
    if(B.size()==0)
        return -1;
    else if(B.size()==3&&(B[0]!=B[1]&&B[1]!=B[2]&&B[0]!=B[2]))
        return -1;
    else
    {
        sort(B.begin(),B.end()); //max O (nlog5)
        for(int i=0;i<B.size();i++)
        {
            if(B[i]==B[i+1])
                return B[i];
        }
    }


}
int main()
{
    vector<int>v={1,2,3,5,6,7};
    int n=repeatedNumber(v);
    cout<<n;
    }

