// Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

// D means the next number is smaller, while I means the next number is greater.

// Notes

// Length of given string s will always equal to n - 1
// Your solution should run in linear time and space.
// Example :

// Input 1:

// n = 3

// s = ID

// Return: [1, 3, 2]

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

//logic is store two elements(f,l) one is 1 other is B
//when I is found push f increment it
//when D is found push l decrement it
//final step push f
//on doing this we are basically making sure that a number is generated according to our requirments
vector<int> findPerm(const string A, int B) {
    int l=B;
    int f=1;
    vector<int>res;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='I')
            {
                res.push_back(f);
                f++;
            }
        if(A[i]=='D')
        {
            res.push_back(l);
            l--;
        }
    }
    res.push_back(f);
    return res;

}
int main()
{
    string s="IDIII";
    int n=6;
    vector<int>res=findPerm(s,n);
    print(res);
}
