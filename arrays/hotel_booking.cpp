#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool mycomp(pair<int,int> a,pair<int,int> b){
     return a.first<b.first;
 }
/*bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int,int>>res;
    for(int i=0;i<arrive.size();i++)
    {
        res.push_back(make_pair(arrive[i],depart[i]));
    }
    sort(res.begin(),res.end(),mycomp);
    for(int t=1;t<res[arrive.size()-1].second;t++)
    {
        int j=K;
      // cout<<"value of rooms: "<<j<<endl;
        for(int i=0;i<arrive.size();i++)
            {
                if(t<res[i].second&&t>=res[i].first)
                {
                    j--;
                   //cout<<"value of j: "<<j<<" ";
                    if(j<0)
                        return false;
                }
            }
    }
    return true;
}
*/
bool hotel(vector<int> &arrive, vector<int> &depart, int k) {
    vector<pair<int,int> >v;
    int n=arrive.size();
    for(int i=0;i<n;i++){
        v.push_back(make_pair(arrive[i],1));
        v.push_back(make_pair(depart[i],-1));
    }
    sort(v.begin(),v.end());
    int count=0;
    for(int i=0;i<2*n;i++){
        count+=v[i].second;
        if(count>k)
         return false;
    }
    return true;
}
int main()
{
    vector<int>A={17, 0, 45, 11, 16, 43, 15, 42, 2, 41, 0, 27, 37, 25, 17, 42, 24, 23, 11, 4, 29, 39, 6, 10, 42, 16, 17, 39, 1 };
    vector<int>B={25, 24, 52, 51, 26, 46, 25, 45, 9, 51, 49, 48, 51, 66, 65, 57, 69, 43, 50, 9, 32, 55, 10, 58, 62, 46, 19, 87, 12};
    bool l=hotel(A,B,);
    cout<<l;
}
