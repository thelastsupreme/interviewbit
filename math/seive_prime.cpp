#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

vector<int>sieve(int A) {
    vector<int>res;
    vector<int>primes(A+1,1);
    primes[0]=0;
    primes[1]=0;
    for(int i=2;i<=sqrt(A);i++)
    {
        if(primes[i]==1)
        {
            for(int j=2;i*j<=A;j++)
                primes[i*j]=0;
        }
    }
    //print(primes);
    for(int i=0;i<=A+1;i++)
        if(primes[i]==1)
            res.push_back(i);
    return res;
}

int main()
{
    int n=10;
    vector<int>a=sieve(10);
    print(a);

}
