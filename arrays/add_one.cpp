#include<iostream>
#include<vector>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

//prakritis code
vector<int> Solution::plusOne(vector<int> &A) {
        int size=A.size();
    int c=0,count=0;
    if(A[size-1]!=9)
    {
        A[size-1]+=1;
    }
    else if(A[size-1]==9)
    {
        A[size-1]=0;
        c=1;
    }
    for(int i=size-2;i>=0 ;i--)
    {
        if(A[i]+c==10)
        {
            A[i]=0;
            c=1;
        }
        else
        {
            A[i]+=c;
            c=0;
        }
    }
    if(c)
        A.insert(A.begin(),c);

    for(int i=0;i<A.size();i++)
    {
        if(A[i]==0)
            count++;
        else
            break;
    }
    A.erase(A.begin(),A.begin()+count);
    return A;

}

//krutikas code
vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> result;
    int n=A.size();

    vector<int> temp;
    int carry=1; int sum=0;
    for(int i=A.size()-1;i>=0;i--)
    {
        sum=A[i]+carry;
        if(sum==10)
        {
            result.push_back(0); carry=1;
        }
        else
        {
            result.push_back(sum);
            carry=0;
        }

    }
    if(carry)
    result.push_back(carry);

    reverse(result.begin(),result.end());
    int count=0;
    for(int j=0;j<result.size()-1;j++)
      if(result[j]==0) count++;
      else break;
    result.erase(result.begin(),result.begin()+count);
    return result;
}
//prabhaths code
vector<int> plusOne(vector<int> &A) {
    vector<int>B;
    int n=A.size();
    int flag=1;
    int k=1;
    int count=0;
    for(int i=0;i<n;i++)
    {    if(A[i]!=9)
           {
            flag=0;
            break;
           }
         else
            flag=1;
    }

    if(flag==1)
    {   B.push_back(1);
        for(int i=0;i<n;i++)
            B.push_back(0);
    }
    else if(flag==0)
    {   for(int i=0;i<n;i++)
           {
            B.push_back(A[i]);
           }
            if(A[n-1]+1>9)
            {
                B[n-2]++;
                B[n-1]=0;
            }
            else
                {B[n-1]++;k=0;}
        for(int i=n-2;i>0;i--)
        {
             if((A[i]+1>9)&&(A[i+1]==9)&&(k==1))
                {
                    B[i-1]++;
                   // cout<<B[i-1];
                    B[i]=0;
                }
            if(A[i]!=9)
                k=0;
        }
    }


    for(int i=0;i<n;i++)
    {
        if(B[i]==0)
            count++;
        else break;
    }
    B.erase(B.begin(),B.begin()+count);
    return B;
}

int main()
{
    vector<int> A={0};
    vector<int>B;
    B=plusOne(A);
    print(B);
}
