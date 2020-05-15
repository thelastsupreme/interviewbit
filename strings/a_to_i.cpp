#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include<sstream>
#include<algorithm>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
/*int atoi(const string A) {
    vector<int>a;
    int ans=0;
    int check=0;
    int neg=0;
    for(int i=0;i<A.size();i++)
    {
       //cout<<A[i]<<endl;
        if(A[i]>='0'&&A[i]<='9')
        {
            a.push_back(A[i]-'0');
            check=1;
        }

        else if(A[i]=='+'&& check==0)
            continue;
        else if(A[i]=='-'&& check==0)
           {
               neg=1;
               continue;
           }
        else
            break;
    }
    print(a);
    cout<<endl;
    long long n=a.size();
    //cout<<n;
    if(n>INT_MAX)
        return INT_MAX;
    if(n<INT_MIN)
        return INT_MIN;
    if(n==0)
        return 0;
    for(int i=0;i<n;i++)
    {
       ans=ans*10+a[i];
       //cout<<ans<<endl;
    }
    if(neg==1)
        return ans*-1;
    return ans;
}
*/
//best solution if stringstream is allowed
/*int atoi(const string A)
{
    stringstream ss;
    ss<<A;
    long long i;
    ss>>i;
    if(i<INT_MIN)
        i=INT_MIN;
    if(i>INT_MAX)
        i=INT_MAX;
    return i;
}
*/
//prakritis code
int atoi(const string A) 
{
    vector<int> ab;
    ab.clear();
    int i=0, sign=0;
    if(A[0]=='-')
    {
        sign =1;
        i=1;
    }
    else if (A[0]=='+')
    {
        i=1;
    }
    while (A[i]!=' ')
    {
        if(A[i]>='0'&&A[i]<='9')
        {
            ab.push_back(A[i]-'0');
            i++;
        }
    }
    reverse(ab.begin(), ab.end());
    int decimal = 1;
    long  res = 0;
    for (auto& it : ab)
    {
        res += it * decimal;
        decimal *= 10;
    }
    if(sign==0 && res>INT_MAX)
        return INT_MAX;
    if(sign == 1 && res>INT_MAX)
        return INT_MIN;
    if(sign ==1)
        return res*(-1);
    return res;
}
 
int main()
{
 string s = "-88297 248252140B12 37239U4622733246I218 9 1303 44 A83793H3G2 1674443R591 4368 7 97";
 int ss=atoi(s);
 cout<<ss;
}


