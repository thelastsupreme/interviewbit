#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void print(std::vector<string> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
unordered_map<char,string>mapp={{'1',"1"},{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"},{'0',"0"}};
void rec_f(vector<string>&res,string &temp,string &A,int curr)
{
    if(curr==A.size())
    {
        res.push_back(temp);
        return;
    }
    else
    {
        string a=mapp[A[curr]];
        for(int i=0;i<a.size();i++)
        {
            temp.push_back(a[i]);
            rec_f(res,temp,A,curr+1);
            temp.pop_back();
        }

    }
}
vector<string> letterCombinations(string A) {
    vector<string>res;
    string temp="";
    rec_f(res,temp,A,0);
    return res;
}


int main()
{
    string s1;
    cin>>s1;
    vector<string>s=letterCombinations(s1);
    print(s);
}
