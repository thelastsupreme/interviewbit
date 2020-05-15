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
vector<int> maxset(vector<int> &A) {
    int n=A.size(),i=0,j=1;
    vector<vector<int>> B(n,vector <int>(1,0)); //2d vector of 1d vector with size 1 and element is 0
    for(int k=0;k<n;k++)
    {
        if(A[k]>=0)
        {
            B[i].push_back(A[k]);
        }
        else
        {
            i++;
            if(i==n)
            {
                cout<<";;";
                vector<int>nne;
                 return nne;
            }
            B[i].push_back(k+1);
            B[i].erase(B[i].begin());
        }
    }

    for(int i=0;i<B.size();i++)
    {
        long long int sum=0,siz=0;
        sum=accumulate(B[i].begin()+1,B[i].end(),0);
        siz=B[i].size();
        B[i].insert(B[i].begin(),siz);
        B[i].insert(B[i].begin(),sum);
       // print(B[i]);
        //cout<<"\n";

    }
    int index=0;
    int b_index=0,b_size=0,b_sum=0;
    for(int i=0;i<B.size();i++)
    {
      int c_sum=B[i][0],c_size=B[i][1],c_index=B[i][2];
        if(c_sum>b_sum)
        {
            b_sum=c_sum;
            b_size=c_size;
            b_index=c_index;
            index=i;
        }
        if((c_sum==b_sum)&&(c_size>b_size))
        {
            b_size=c_size;
            b_index=c_index;
            index=i;
        }
        if((c_sum==b_sum)&&(c_size==b_size)&&(c_index<b_index))
        {
            b_index=c_index;
            index=i;
        }
    }
    B[index].erase(B[index].begin(),B[index].begin()+3);
    return B[index];

}
int main()
{
  vector<int>A={9,3,4,2,-1,2,0,7,-2,8,-5 };
  vector<int>B=maxset(A);
  print(B);
}
