#include<iostream>
#include<vector>

using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
void r_fxn(int A,int B,vector<vector<int>>&res,vector<int>temp,int curr)
{
    if(B==0)
    {
        res.push_back(temp);
        return;
    }
    for(int i=curr;i<=A;i++)
    {
        temp.push_back(i);
        r_fxn(A,B-1,res,temp,i+1);
        temp.pop_back();
    }

}
vector<vector<int> >combine(int A, int B) {
    vector<vector<int>>res;
    vector<int>temp;
    r_fxn(A,B,res,temp,1);
    return res;
}

int main()
{
    vector<vector<int>>ans=combine(4,2);
    for(int i=0;i<ans.size();i++)
    {
        print(ans[i]);
        cout<<endl;
    }

}
