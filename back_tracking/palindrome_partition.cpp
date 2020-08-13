#include <bits/stdc++.h>
using namespace std;



//prabhaths code
bool isPalindrome(string A) {
    string B;
    int n =A.size();
    //cout<<B<<endl;
    for(int i=0;i<n/2;i++)
    {
        if(A[i]!=A[n-i-1])
        {
            return 0;
        }
    }
    return 1;


}
void rec_f(vector<vector<string>>&res,vector<string>&temp,int curr,string A)
{
    if(curr==A.length())
    {
        res.push_back(temp);
    }

    else
    {
        string t="";
        for(int i=curr;i<A.length();i++)
        {
            t+=A[i];
            if(isPalindrome(t))
            {
                temp.push_back(t);
                rec_f(res,temp,i+1,A);
                temp.pop_back();
            }
        }
    }
}
vector<vector<string> > partition(string A) {
    vector<vector<string>>res;
    vector<string>temp;
    rec_f(res,temp,0,A);
    return res;
}

//prakritis code
void helper(int n, int s, vector<vector<string>> &res,vector<string>&cur, string str)
{
    if(s>=n)
        {
            res.push_back(cur);
            return;
        }
    else
    {
        for(int i=s;i<n;i++)
        {
            if(isPalindrome(str.substr(s,i-s+1)))
            {
                cur.push_back(str.substr(s,i-s+1));
                helper(n,i+1,res,cur,str);
                cur.pop_back();
            }
        }
    }
}
vector<vector<string>> partition_1(string A)
{
    int n=A.size();
    vector<vector<string>> F;
    vector<string> c;
    helper(n,0,F,c,A);

    return F;
}
