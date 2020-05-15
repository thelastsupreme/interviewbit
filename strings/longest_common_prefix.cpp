#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(string a,string b)
{
    return(a.size()<b.size());
}

string longestCommonPrefix(vector<string>&A) {
    sort(A.begin(),A.end());
    string a  = "";
    if(A.size() == 0)
    {
        return a;
    }
    if(A.size() == 1)
    {
        return A[0];
    }
    string result = "";
    for(int i=0,j=0;i<A[0].length()&&j<A[1].length();i++,j++)
    {
        if(A[0][i]!=A[1][i])
        {
            break;
        }
        result+=A[0][i];
    }

    for(int i=2;i<A.size();i++)
    {
        string temp = result;
        string lcs = "";
        for(int j=0,k=0;j<A[i].length()&&k<temp.length();j++,k++)
        {
            if(A[i][j] != temp[k])
            {
                break;
            }
            lcs+=A[i][j];
        }
        result = lcs;
    }
    return result;
}
///// best_approach/////
string longestCommonPrefix(vector<string> &A) {
    string res="";
    char curr;
    if(A.size()==0)
        return res;
    else if(A.size()==1)
    {
        return A[0];
    }
    for(int i=0;i<A[0].size();i++)
    {
        curr=A[0][i];
        for (int j=1 ; j<A.size(); j++)
        {
            if (A[j][i] != curr)
                return res;
        }
         res.push_back(curr);
    }
    return res;
}
//even better approach//
string Solution::longestCommonPrefix(vector &A)
{
    string s1=A[0];
    int l=A.size();
    if(l==1)
    {
        return(A[0]);
    }
    int x1=INT_MAX;
    int x;
    for(int i=1;i<l;i++)
    {
        x=0;
        while(s1[x]==A[i][x])
        {
            x++;
        }
        if(x<=x1)
            x1=x;
    }

    string sub=s1.substr(0,x1);
    return sub;
}
int main()
{
    vector<string>n={"abcdefgh", "aefghijk", "abcefgh"};
    string comm=longestCommonPrefix(n);
    cout<<comm;
}
