#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
using namespace std;
int power(string A) {
    stringstream ss;
    ss<<A;
    long double n;
    ss>>n;
    if(n==1)
        return 0; //though 2 power 0 is 1 question doesnt allow
    long double l=fmod(n,10);
    while(n>=2)
    {
        cout<<"n :"<<n<<endl;
        cout<<"l :"<<l<<endl;
        if(l==1||l==3||l==5||l==7||l==9)
        {
            return 0;
        }
        n/=2;
        l=fmod(n,10);
    }
    return 1;
}

//prakritis code
int power(string A)
{
    stringstream ss;
    ss<<A;
    long double a;
    ss>>a;
    long double n=a;
    if(a==1)
        return 0;
    if(a==2)
        return 1;
    int i=2;
    while(n>2)
    {
        long double d = 1/(long double)i;
       // cout<<"d :"<<d<<endl;
        n=pow(a,d);
        if(pow(round(n),i)==a)
            return 1;
        i++;
    }
    return 0;
}
int main()
{
    string s="147573952589676412928";
    int a=power(s);
    cout<<a;
}