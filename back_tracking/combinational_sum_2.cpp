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

//prabhaths code
int sumAll(const vector<int>& v) {
    int sum = 0;
        for (int k : v) { sum += k; }
    return sum;
}
void r_comb_sum(vector<vector<int>>&res,vector<int>temp,vector<int>A,int B,int curr)
{
    if(sumAll(temp)>B)
    {
        return;
    }
    if(sumAll(temp)==B)
    {
        sort(temp.begin(),temp.end());
        if(find(res.begin(),res.end(),temp)==res.end())
            res.push_back(temp);
    }
    for(int i=curr;i<A.size();i++)
    {
        temp.push_back(A[i]);
        r_comb_sum(res,temp,A,B,i+1);
        temp.pop_back();
    }
}
vector<vector<int> >combinationSum(vector<int> &A, int B) {
    vector<vector<int>>res;
    vector<int>temp;
    r_comb_sum(res,temp,A,B,0);
    sort(res.begin(),res.end());
    return res;
}

int main()
{
    vector<int>A={8, 10, 6, 11,1,16, 8 };
    vector<vector<int>>ans =combinationSum(A,28);
    for(int i=0;i<ans.size();i++)
    {
        print(ans[i]);
        cout<<endl;
    }

}

