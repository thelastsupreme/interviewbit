#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

vector<int> grayCode(int A)
{
    vector<int>res;
    res.push_back(0);
    for(int i=0;i<A;i++)
    {
        vector<int>temp;
        for(int j=res.size()-1;j>=0;j--)
            temp.push_back(res[j]+pow(2,i));
        res.insert(res.end(),temp.begin(),temp.end());
    }
    return res;  
}

int main()
{
    vector<int>ans=grayCode(4);
    print(ans);
}
