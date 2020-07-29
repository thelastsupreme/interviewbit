// You are given a sequence of black and white horses, and a set of K stables numbered 1 to K. You have to accommodate the horses into the stables in such a way that the following conditions are satisfied:

// You fill the horses into the stables preserving the relative order of horses. For instance, you cannot put horse 1 into stable 2 and horse 2 into stable 1. You have to preserve the ordering of the horses.
// No stable should be empty and no horse should be left unaccommodated.
// Take the product (number of white horses * number of black horses) for each stable and take the sum of all these products. This value should be the minimum among all possible accommodation arrangements
// Example:


// Input: {WWWB} , K = 2
// Output: 0

// Explanation:
// We have 3 choices {W, WWB}, {WW, WB}, {WWW, B}
// for first choice we will get 1*0 + 2*1 = 2.
// for second choice we will get 2*0 + 1*1 = 1.
// for third choice we will get 3*0 + 0*1 = 0.

// Of the 3 choices, the third choice is the best option. 

#include <bits/stdc++.h>
using namespace std;

//my approach
unordered_map<string,int>mp;
int countW(string A)
{
    return count(A.begin(),A.end(),'W');
}
int countB(string A)
{
    return count(A.begin(),A.end(),'B');
}

int arrange(string A,int B)
{
    stringstream ss;
    ss<<A<<" "<<B;
    // cout<<"string : "<<A<<endl;
    string key=ss.str();
    if(mp.find(key)!=mp.end())
        return mp[key];
    
    if(countW(A)==0||countB(A)==0)
        return 0;

    if(B==0)
        return countW(A)*countB(A);

    int result=INT_MAX;
    for(int k=1;k<A.size();k++)
    {
        string left=A.substr(0,k);
        string right=A.substr(k,A.size()-k);
        for(int i=0;i<B;i++)
        {
            // cout<<"left : "<<left<<endl;
            int l=arrange(left,i);
            // cout<<l<<endl;
            // cout<<"right : "<<right<<endl;
            int r=arrange(right,B-i-1);
            // cout<<r<<endl;
            result=min(l+r,result);
        }
    }
    return mp[key]=result;
}


/////////////////EDITORIAL SOULTION////////////////////////////
vector<vector<int>> dp;

int rec(int start, int stables, string str, int K)
{
    int N = str.size();
    if (start == N)
    {
        if (stables == K)
            return 0;
        return INT_MAX;
    }

    if (stables == K)
        return INT_MAX;

    if (dp[start][stables] != -1)
        return dp[start][stables];

    int W = 0;
    int B = 0;
    int ans = INT_MAX;

    for (int i = start; i < N; ++i)
    {
        W += str[i] == 'W';
        B += str[i] == 'B';
        if (W * B > ans)
            break;
        int Temp = rec(i + 1, stables + 1, str, K);
        if (Temp != INT_MAX)
        {
            ans = min(ans, Temp + (W * B));
        }
    }

    return dp[start][stables] = ans;
}

int arrange_editorial(string str, int K)
{
    int N = str.size();
    dp.clear();
    dp.resize(N, vector<int>(K, -1));

    int ans = rec(0, 0, str, K);
    return ans == INT_MAX ? -1 : ans;
}
int main()
{
    cout<<arrange_editorial("BWWWWBBWWBWBWWBBBBBWBWWBBBWWWWBBBW",27);
}