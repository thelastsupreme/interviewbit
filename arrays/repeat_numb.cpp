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
int repeatedNumber(const vector<int> &A) {

     vector <bool> v(A.size());
    fill(v.begin(), v.end(), true);

    for(int i=0;i<A.size();i++){
           // cout<<i;
        if(v[A[i]]){
            v[A[i]]=false;
        }

        else
            return A[i];
    }
}
int main()
{
    vector<int>v={1,2,3,5,2};
    int n=repeatedNumber(v);
    
}
