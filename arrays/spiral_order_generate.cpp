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
vector<vector<int> > generateMatrix(int A) {
    vector<vector<int>>result( A , vector<int> (A, 0));
    int T=0,B=A-1,L=0,R=A-1;
    int dir=0,numb=1;
    while(T<=B&&L<=R)
    {
        if(dir==0)
        {
            for(int i=L;i<=R;i++)
                {
                    result[T][i]=numb;
                    numb++;
                }
            T++;
        }
        else if(dir==1)
        {
            for(int i=T;i<=B;i++)
                {
                    result[i][R]=numb;
                    numb++;
                }
            R--;
        }
        else if(dir==2)
        {
            for(int i=R;i>=L;i--)
                {
                    result[B][i]=numb;
                    numb++;
                }
            B--;
        }
        else if(dir==3)
        {
            for(int i=B;i>=T;i--)
               {
                    result[i][L]=numb;
                    numb++;
                }
            L++;
        }
        dir=(dir+1)%4;

    }
    return result;
}
int main()
{
    int n=4;
    vector<vector<int>>A=generateMatrix(n);
    print(A[1]);
}
