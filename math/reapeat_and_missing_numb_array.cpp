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
void printb(std::vector<bool> const &input)
{
	for (int i = 0; i < input.size(); i++) {
            cout << input[i];
	}
}
//using bool only cause of memory constraint.
vector<int> repeatedNumber(const vector<int> &A) {

    vector <bool> v(A.size()+1);
    fill(v.begin(), v.end(), true);
    vector<int>res;
    for(int i=0;i<A.size();i++){
            //cout<<i;
        if(v[A[i]]){
            v[A[i]]=false;
        }

        else
            res.push_back(A[i]);
    }
    for(int i=1;i<v.size();i++)
    {
        if(v[i]==true)
            res.push_back(i);
    }
   /* for(int i=1;i<=A.size();i++)
    {
        if (find(A.begin(), A.end(), i) != A.end())
            continue;
        else
            res.push_back(i);
    }
    */
    return res;

}
int main()
{
    vector<int>v={3,1,2,5,3};
    vector<int>c=repeatedNumber(v);
    print(c);

}
