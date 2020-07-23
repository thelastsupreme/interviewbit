// You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
// Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
// If A is already sorted, output -1.

// Example :

// Input 1:

// A = [1, 3, 2, 4, 5]

// Return: [1, 2]

// Input 2:

// A = [1, 2, 3, 4, 5]

// Return: [-1]
// In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.

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

vector<int> subUnsort(vector<int> &A)
{
    int n = A.size();
    vector<int> res;    
    vector<int> B;   //using a duplicate and sorting it and checking where the mismatch is
    int flag = 0; 
    for (int i = 0; i < n; i++)
    {
        B.push_back(A[i]);
    }
    sort(B.begin(), B.end());
    for (int i = 0; i < n; i++)
    {
        if (A[i] != B[i])
        {
            res.push_back(i);      //pushing all mismatched into result
            flag = 1;
        }
    }
    int m = res.size();
    if (flag == 0)
    {
        res.push_back(-1);
        return res;
    }

    else
    {
        for (int i = 1; i < m - 1; i++)
            res.erase(res.begin() + 1);  //and then deleting all indices excpet first and last 
    }
    return res;
}
/*  most efficient
//use two pointers to get the boundary areas s:start e :end where array isnt sorted
//now get the max and min in that boundaries
//now get the indices of those numbers
//return them in res vector 

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

    vector<int>v={ 4, 14, 10, 13, 18, 13, 10, 19, 18, 10, 20, 19, 19, 13, 13, 13, 100 };
    vector<int>a=subUnsort(v);
    print(a);
}
