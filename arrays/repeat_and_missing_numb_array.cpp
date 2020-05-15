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
//using bool only cause of memory constraint.
vector<int>repeatedNumber(const vector<int> &A) {
    vector <bool> v(A.size()+1);
    fill(v.begin(), v.end(), true);
    vector<int>res;
    for(int i=0;i<A.size();i++){
            //cout<<i;
        if(v[A[i]]){
            v[A[i]]=false;
        }

        else
            res.push_back(A[i]);
    }
    for(int i=1;i<v.size();i++)
    {
        if(v[i]==true)
            res.push_back(i);
    }
    return res;
}
//best approach
vector<int> repeatedNumber(const vector<int> &A) 
{
    long long int n = A.size();
    long long int sum = (n * (n+1) ) /2;
    long long int sumsq = (n * (n +1) *(2*n +1) )/6;
    long long int a=0, b=0;
    
    for(int i=0;i<A.size(); i++){
       sum -= (long long int)A[i];
       sumsq -= (long long int)A[i]*(long long int)A[i];
    }
    
    a = (sum + sumsq/sum)/2;
    b= a - sum;
    vector <int> ans;
    
    ans.push_back(b);
    ans.push_back(a);
    return ans;

    
}
//hybrid approach
vector<int>repeatedNumber(const vector<int> &A) {
    vector <bool> v(A.size()+1);
    fill(v.begin(), v.end(), true);
    long long int n=A.size();
    long long int sum = (n * (n+1) ) /2;
    long long int temp=0;
    vector<int>res;
    for(int i=0;i<A.size();i++){
            //cout<<i;
        if(v[A[i]]){
            v[A[i]]=false;
        }

        else
        {
            res.push_back(A[i]);
        }
        sum-=A[i];
    }
    temp=sum+res[0];
    res.push_back(temp);
    return res;
}
//krutikas code
vector<int>+-repeatedNumber(const vector<int> &A) {
    
    vector<int> ab(2); 
    int a,b;  
    int countt;
    int flaga=0; int flagb=0;
    for(int i=1;i<=A.size();i++)
    {
        countt=count(A.begin(),A.end(),i);
        if(countt==0)
        {   ab[1]=i; flagb=1;
        }
        else if(countt==2)
        {   ab[0]=i;  flaga=1;
        }
        if(flaga&&flagb)
         break;
    }
    return ab;
}

int main()
{
    vector<int>v={1,2,3,5,2};
    vector<int>ans=repeatedNumber(v);
    print(ans);
    
}
