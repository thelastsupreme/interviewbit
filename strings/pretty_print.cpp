#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
//prakritis code
/*vector<vector<int>> prettyPrint(int A)
{
    int n=2*A-1;
    int lim=n;
    int temp=0;
    vector<vector<int>> v (n,vector<int> (n));
    while(A>0)
    {
        for(auto i=temp;i<lim;i++)
        {
            for(auto j=temp;j<lim;j++)
            {
                v[i][j]=A;
            }
        }
        A--;
        lim--;
        temp++;
    }
    return v;
}
*/
//krutikas code //using fill
vector<vector<int> > prettyPrint(int A) {
    int n=2*A-1;
    vector<vector<int>> l(n,vector<int>(n));
    if(A==0) return l;

    vector<vector<int>> res(n,vector<int>(n,0));

    for(int i=0;i<n/2+1;i++)
    {
        for(int j=i;j<n-i;j++)
        {
            fill(res[j].begin()+i,res[j].end()-i,A);
        }
        A--;
    }
    return res;
}


/*
//prabhaths code
vector<vector<int> > prettyPrint(int A) {
   vector<vector<int>>result( 2*A-1 , vector<int> (2*A-1, 0));
    int T=0,B=2*A-2,L=0,R=2*A-2;
    int dir=0,numb=A;
    while(T<=B&&L<=R)
    {
        if(dir==0)
        {
            for(int i=L;i<=R;i++)
                {
                    result[T][i]=numb;
                    //numb++;
                }
            T++;
        }
        else if(dir==1)
        {
            for(int i=T;i<=B;i++)
                {
                    result[i][R]=numb;
                   // numb++;
                }
            R--;
        }
        else if(dir==2)
        {
            for(int i=R;i>=L;i--)
                {
                    result[B][i]=numb;
                   // numb++;
                }
            B--;
        }
        else if(dir==3)
        {
            for(int i=B;i>=T;i--)
               {
                    result[i][L]=numb;
                    //numb--;
                }
                numb--;
            L++;
        }
        dir=(dir+1)%4;

    }
    return result;
}
*/
int main()
{
    int n=200;
    vector<vector<int>>A=prettyPrint(n);
    for(int i=0;i<2*n-1;i++)
        {
            print(A[i]);
            cout<<endl;
        }

}

