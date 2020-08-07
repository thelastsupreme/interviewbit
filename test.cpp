#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

void print(vector<int> &input)
{
	for (int i = 0; i < input.size(); i++) {
		cout << input.at(i) << ' ';
	}
    cout<<endl;
}

void print_map(unordered_map<int,int>&map)
{
    auto it=map.begin();
    while(it!=map.end())
    {
        cout<<it->first<<" --> "<<it->second<<endl;
        it++;
    }
}
void print_matrix(vector<vector<int>>&matrix)
{
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    vector<int>arr={7,10,12};
}