// Given a list of non negative integers, arrange them such that they form the largest number.

// For example:

// Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

// Note: The result may be very large, so you need to return a string instead of an integer.

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
//logic: its just a tricky way to sort so try to use a function which solves our problem
//in this case the trick lies when we were allowed to use strings
//cause "30"+"3"<"3+"30"
bool sort_n(string a,string b)  //key function for stl sort
{
    string s1=a+b;
    string s2=b+a;
    if(s1>=s2)       //return true if larger string is generated
        return true;
    else
        return false;

}
string largestNumber(const vector<int> &A) {
    string ress="";
    stringstream ss;   //used stringstream cause to_string doesnt work
    vector<string>B;
    for(int i=0;i<A.size();i++)
    {
        ss<<A[i];
        string temp=ss.str(); //stream to string coversion
        ss.str("");           //empty it remeber clear doesnt empty it
        B.push_back(temp);
    }
    sort(B.begin(),B.end(),sort_n); //sort based on key function
    for(int i=0;i<A.size();i++)
        ress+=B[i];              //append to result
    int k=0;
    while(ress[k]=='0'){
        k++;                //count number of zeros
    }
    if(k==ress.length())
     ress="0";           //result is 0 if all elements are zeroes 
    return ress;
}

int main()
{

    vector<int>v={3,30,34,5,9};
    string s=largestNumber(v);
    cout<<s;
}
