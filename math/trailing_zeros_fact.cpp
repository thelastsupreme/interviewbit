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
int number_of_fives(int n)
{
    int count=0;
    while(n%5==0){
        n/=5;
        count++;
    }
    return count;
}
int trailingZeroes(int A) {
    int res=0;
    for(int i=5;i<=A;i+=5)
        res+=number_of_fives(i);
    return res;
}
/*
prakritis code
int Solution::trailingZeroes(int A)
{
    int count=0;
    for (int i = 5; A/i>= 1; i *= 5)
      count += A/ i;
     
     return count;
}
*/

int main()
{
   int n=trailingZeroes(9247);
   cout<<n;
}

