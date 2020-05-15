#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isInFirst(float f) {
        if((f > 0) && (f < 2.0/3.0)) {
            return true;
        }
        return false;
    }
bool isInSecond(float f) {
        if((f >= 2.0/3.0) && (f < 1.0)) {
            return true;
        }
        return false;
    }
bool isInThird(float f) {
        if((f >= 1.0) && (f < 2.0)) {
            return true;
        }
        return false;
    }
int solve(vector<string> &A) {
int n=A.size(),i;
vector<float>v;
for(i=0;i<n;i++)
{
    v.push_back(stof(A[i]));
}
float a=v[0],b=v[1],c=v[2];

float mx=0;
for(i=3;i<n;i++)
{
    if(a+b+c<2 && a+b+c>1)
        return 1;
    else if(a+b+c>2) //greater than 2 replace max with current
    {
        if(a>b && a>c)
            a=v[i];
        else if(b>a && b>c)
            b=v[i];
        else
            c=v[i];
    }
    else            //less than 1 replace min with current
    {
        if(a<b && a<c)
            a=v[i];
        else if(b<a && b<c)
            b=v[i];
        else
            c=v[i];

    }
}
if(a+b+c>1 && a+b+c<2)
    return 1;
else
    return 0;
}

int main()
  {
      vector<string> s={"2.673662", "2.419159", "0.573816", "2.454376", "0.403605", "2.503658", "0.806191" };
      int n=solve(s);
      cout<<n;
  }

