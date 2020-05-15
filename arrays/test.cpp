#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <string.h>
#include <limits.h>
#include<algorithm>
using namespace std;

int lengthOfLastWord(const string A) {
    string A1=A;
    if(A1.length()==0)
        return 0;
    int res=1;
    reverse(A1.begin(), A1.end());
    cout<<"A1:"<<A1<<endl;
    int n = A1.length();
    char s[n+1];
    strcpy(s,A1.c_str());
    char* str=s;
    for(int i=0; i<n;i++)
        cout<<"at i"<<i<<" :"<<str[i]<<endl;
    while(*str)
    {
        if(*str ==' ')
        {
            res=0;
            cout<<"res "<<res<<endl;
        }
        res++;
        str++;
    }
    return res-1;
}
int main()
{
    string abc= "the sky is pinkaalol";
    int out=lengthOfLastWord(abc);
    cout<<"Ans is: "<<out<<"\n";
}

