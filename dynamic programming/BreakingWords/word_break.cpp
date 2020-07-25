#include <bits/stdc++.h>
using namespace std;


// unordered_map<string,bool>mp;
// bool Part(string A){
//     // cout<<A<<endl;
//     if(A.length()==0)
//         return;
//     if(mp.find(A)!=mp.end()){
//         return true;
//     }
//     for(int k=1;k<=A.size()-1;k++){
//         bool l=Part(A.substr(0,k));
//         bool r=Part(A.substr(k+1,A.size()-k));
//     }
// }
// int wordBreak(string A, vector<string> &B) {
//     mp.clear();
//     for(int i=0;i<B.size();i++){
//         mp.insert(make_pair(B[i],false));
//     }
//     // auto it=mp.begin();
//     // while(it!=mp.end()){
//     //     cout<<it->first<<"--->"<<it->second<<endl;
//     //     it++;
//     // }
//     Part(A);

//     auto it=mp.begin();
//     while(it!=mp.end()){
//         cout<<it->first<<"--->"<<it->second<<endl;
//         it++;
//     }

//     it=mp.begin();
//     while(it!=mp.end()){
//         if(it->second==false)
//             return 0;
//         it++;
//     }
//     return 1;
// }
bool contains(string temp,vector<string>&B)
{
    // cout<<"temp "<<temp<<endl;
    if(temp==" ")
        return true;
    for(int i=0;i<B.size();i++)
    {
        if(B[i]==temp)
            return true;
    }
    return false;
}
int wordBreak(string A, vector<string> &B) {
    // cout<<A<<endl;
    if(A.size()==0)
        return 1;
    for(int k=1;k<=A.size();k++)
    {
        // cout<<k<<endl;
        if(contains(A.substr(0,k),B)&&(wordBreak(A.substr(k,A.size()-k),B)))
            return 1;
    }
    return 0;
}
//optimal solution
int wordBreak(string a, vector<string> &b) {
    if(b.empty()) return 0;
    unordered_set<string> s;
    for(string str : b) s.insert(str);
    vector<bool> dp(a.size()+1,0);//dp[i] is true if a valid sequence ends there.
    dp[0] = 1;
    for(int i=1; i<=a.size(); i++)
    {
        for(int j=i-1; j>=0; j--)
        {
            if(dp[j])
            {
                if(s.find(a.substr(j,i-j)) != s.end())
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
    }
    return dp[a.size()];
}

int main(){
    string A="myinterviewtrainer";
    vector<string>B={"interview", "my", "trainer" };
    cout<<wordBreak(A,B);
}