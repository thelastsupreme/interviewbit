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

//crude logic approach

/*vector<int> Solution::primesum(int A) {
     vector<int>res; //store all primes less than n
    vector<int>pairr; //final pair
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
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res.size();j++)
        {
            if(res[i]+res[j]==A)
            {
                pairr.push_back(res[i]);
                pairr.push_back(res[j]);
                return pairr;
            }
        }
    }
}
//saved space by directly putting the condition in initial if case
vector<int>primesum(int A) {
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
    {
        for(int j=0;j<A+1;j++)
           {
            if(primes[i]==1&&primes[j]==1&&i+j==A)
               {
                res.push_back(i);
                res.push_back(j);
                return res;
               }
           }
    }

}
*/
//final change just use bool cause of memory constraint
vector<int> primesum(int A) {
    vector<int>res;
    vector<bool>primes(A+1,1);
    primes[0]=false;
    primes[1]=false;
    for(int i=2;i<=sqrt(A);i++)
    {
        if(primes[i]==true)
        {
            for(int j=2;i*j<=A;j++)
                primes[i*j]=false;
        }
    }
    //print(primes);
    for(int i=0;i<=A+1;i++)
    {
        for(int j=0;j<A+1;j++)
           {
            if(primes[i]==true&&primes[j]==true&&i+j==A)
               {
                res.push_back(i);
                res.push_back(j);
                return res;
               }
           }
    }
}
/*
fastest approach
int isPrime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

vector<int> Solution::primesum(int n) {
    vector<int> v;
    for(int i=2;i<=n/2;i++)
    {
        if( isPrime(i) && isPrime(n-i) )
        {
            v.push_back(i);
            v.push_back(n-i);
            return v;
        }
    }
}

*/
/*
//prakritis code
bool isPrime(int n)
{
    if(n<2)
        return false;
    if(n<4)
        return true;
    if(n%2==0)
        return false;
    int i=3;
    while(i<=sqrt(n))
    {
        if(n%i==0)
            return false;
        i=i+2;
    }
    return true;
   
}
vector<int> Solution::primesum(int A) {
    int i=2;
    vector<int> res;
    while(i<A)
    {
        bool flag=isPrime(i);
        if(flag)
        {
            flag=isPrime(A-i);
            if(flag)
            {
                res.push_back(i);
                res.push_back(A-i);
                return res;
            }
        }
        i++;
    }
}
*/
/*
krutikas code
bool isPrime(int n)
{
    bool flag=true;
    for(int i = 2; i <=sqrt(n); i++)
  {
      if(n % i == 0)
      {
          flag=false;
          break;
      }
  }
  return flag;
}
vector<int> Solution::primesum(int A) {
   
    vector<int> sol;
    //vector<int> primes;
    for(int i=2;i<A;i++)
    {
        if(isPrime(i)==true&&isPrime(A-i))
        {  
            sol.push_back(i);
            sol.push_back(A-i);
            break;
        }
    }
   
    return sol;
}
*/
int main()
{
    vector<int>a=primesum(126);
    print(a);

}
