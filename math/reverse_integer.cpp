#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
int rreverse(int A) {
    if(A==0)
        return A;
    if(A>0)
    {
        //int B=A;
        int res=0;
        while(A)
        {
            res=res*10+A%10;
             A/=10;
        }
        return res;
    }
    if(A<0)
    {
        int B=-A;
        //cout<<"B = "<<B<<endl;
        long long int res=0;
       // cout<<INT_MAX<<endl;
        while(B)
        {
            res=res*10+B%10;
            B/=10;
            if(res>INT_MAX)
                return 0;
           // cout<<"res = "<<res<<endl;
        }
       // cout<<res<<endl;
        res=res*(-1);
       // cout<<res<<endl;
        if(res<INT_MIN)
            return 0;
        return res;
    }
}

int main()
{
   int n=rreverse(-1146467285);
   cout<<n;
}
