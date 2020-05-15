#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

vector<int> subUnsort(vector<int> &A) {
    int n=A.size();
    vector<int>res;
    vector<int>B;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        B.push_back(A[i]);
    }
    sort(B.begin(),B.end());
    for(int i=0;i<n;i++)
    {
        if(A[i]!=B[i])
          {
              res.push_back(i);
              flag=1;
          }

    }
    int m=res.size();
    if(flag==0)
    {
        res.push_back(-1);
        return res;
    }

    else
       {
         for(int i=1;i<m-1;i++)
            res.erase(res.begin()+1);

       }
           return res;

}
/*  most efficient
vector<int> Solution::subUnsort(vector<int> &A) {
      int n=A.size();
    vector<int>res;
    int s=-1,e=-1;
    for(int i=0;i<n-1;i++){
        if(A[i]>A[i+1]){
            s=i;
            break;
        }
    }
    if(s==-1){
        res.push_back(-1);
        return res;
    }
    for(int i=n-1;i>0;i--){
        if(A[i]<A[i-1]){
            e=i;
            break;
        }
    }
   // cout<<s<<" "<<e<<endl;
    int minm=A[s],maxm=A[s];
    for(int i=s+1;i<=e;i++){
        if(A[i]<minm)
         minm=A[i];
        else if(A[i]>maxm)
         maxm=A[i];
    }
    for(int i=0;i<s;i++){
        if(A[i]>minm){
         s=i;
         break;
        }
    }
    for(int i=n-1;i>e;i--){
        if(A[i]<maxm){
         e=i;
         break;
        }
    }
    res.push_back(s);
    res.push_back(e);
    return res;

}*/
int main()
{

    vector<int>v={ 4, 14, 10, 13, 18, 13, 10, 19, 18, 10, 20, 19, 19, 13, 13, 13, 10 };
    vector<int>a=subUnsort(v);
    print(a);
}
