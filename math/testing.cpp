#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}


int main()
{
   int n=0;
   char c=n+'A';
   cout<<c;
}

