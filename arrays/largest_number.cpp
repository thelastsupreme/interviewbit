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
int countt(string s, char c)
{
    // Count variable
    int res = 0;

    for (int i=0;i<s.length();i++)

        // checking character in string
        if (s[i] == c)
            res++;

    return res;
}
bool sort_n(string a,string b)
{
    string s1=a+b;
    string s2=b+a;
    if(s1>=s2)
        return true;
    else
        return false;

}
string largestNumber(const vector<int> &A) {
    string ress="";
    vector<string>B;
    for(int i=0;i<A.size();i++)
    {
        B.push_back(to_string(A[i]));
    }
    sort(B.begin(),B.end(),sort_n);
    for(int i=0;i<A.size();i++)
        ress+=B[i];
    int k=0;
    while(ress[k]=='0'){
        k++;
    }
    if(k==ress.length())
     ress="0";
    return ress;
}
//prakritis code
string Solution::largestNumber(const vector<int> &A)
{
    string res = "";
    vector<string> B;
    for(int i=0; i<A.size();i++)
        B.push_back(to_string(A[i]));
    sort(B.begin(),B.end(),compare);
    for(int i = 0; i < B.size(); i++){
        res +=  B[i];
    }
    if(res[0] == '0')    //best instead of using a while like prabhath did
    {
        return "0";
    }
    return res;
}


int main()
{

    vector<int>v={3,30,34,5,9};
    string s=largestNumber(v);
    cout<<s;
}
