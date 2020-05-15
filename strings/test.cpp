#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

//krutika code
string Solution::convertToTitle(int A) {
    char c[27]={'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    string sol="";
    int t=A;
    while(t!=0)
    {
        if(t%26==0)
        {
            t=t-26;
            t=t/26;
            sol.push_back('Z');
        }
        else
        {
        sol.push_back(c[(t%26)]);
        t=t/26;
        }
    }
    reverse(sol.begin(),sol.end()); //
    return sol;

}
// Prakriti code
string Solution::convertToTitle(int A) {
    int n=A;
    string ans="";
    while(n){
        int rem=n%26;
        if(rem){
            char c=rem-1+'A';
            string s;
            s.push_back(c);
            ans.insert(0,s);
            n=n/26;
        }
        else
        {
            ans.insert(0,"Z");
            n=n/26-1;
        }
    }
    return ans;
}


int main()
{
  string s=convertToTitle(53);
  cout<<s;

}


