// You are given the following :

// A positive number N
// Heights : A list of heights of N persons standing in a queue
// Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P
// You need to return list of actual order of persons’s height

// Consider that heights will be unique

// Example

// Input : 
// Heights: 5 3 2 6 1 4
// InFronts: 0 1 2 0 3 2
// Output : 
// actual order is: 5 3 2 1 6 4 
// So, you can see that for the person with height 5, there is no one taller than him who is in front of him, and hence Infronts has 0 for him.

// For person with height 3, there is 1 person ( Height : 5 ) in front of him who is taller than him.

// You can do similar inference for other people in the list.
#include <bits/stdc++.h>
using namespace std;

void print(vector<pair<int,int>>A)
{
    for(int i=0;i<A.size();i++)
    {
        cout<<A[i].first<<" "<<A[i].second<<endl;
    }
    cout<<endl;
}
void print_vector(vector<int>A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
vector<int>order(vector<int> &A, vector<int> &B)
{
    vector<pair<int, int>> v;
    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(A[i], B[i]));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    // print(v);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.insert(ans.end() - (i - v[i].second), v[i].first); 
        //i-v[i].second gives us the position cause in the array
        //cause in the array elements whose height are greater are present while our element is being inserted
        print_vector(ans);
    }

    return ans;
}


int main()
{
    vector<int>A={5,3,2,6,1,4};
    vector<int>B={0,1,2,0,3,2};
    vector<int>res=order(A,B);
}