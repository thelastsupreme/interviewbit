#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_vect(vector<vector<int> >&input)
{
	for (int i = 0; i < input.size(); i++) {
		for(int j=0;j<input[i].size();j++)
        {
            cout << input[i][j] << ' ';
        }
        cout<<endl;
	}
}
void print(std::vector<bool> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

int maximumGap(const vector<int> &A) {
    int n=A.size();
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(A[i],i));
    }
    sort(v.begin(),v.end());
    int ans=0;
    int rmax=v[n-1].second;
    for(int i=n-2;i>=0;i--){
        ans=max(ans,rmax-v[i].second);
        rmax=max(rmax,v[i].second);
    }
    return ans;
}
//best approach
int Solution::maximumGap(const vector<int> &a) {
    int n = a.size();
    int right[n];
    right[n-1] = a[n-1];
    for(int i=n-2; i>=0; i--) right[i] = max(right[i+1], a[i]);
    int ans = 0;
    int i = 0; int j=0;
    while( i<n  && j<n ){
        if( a[i] <= right[j]){
            ans = max(ans, j-i);
            j++;
        }
        else i++;
    }
    return ans;
}
//prakritis code
int Solution::maximumGap(const vector<int> &A) 
{
    int i=0,j=0;
    int res=-1;
    int i_idx=0,j_idx=0;
    vector<pair<int,int>> p(A.size(),make_pair(0,0));
    for(int i=0;i<A.size();i++)
    {
        p.push_back(make_pair(A[i],i));
    }
    if(A.size()<=1)
        return 0;
    sort(p.begin(),p.end());
    while(i<A.size() && j<A.size())
    {
        if(A[i]>A[j])
        {
            i++;
            j=i+1;
        }
        else if(A[i]<=A[j])
        { 
            if(j-i>res)
            {
                res=j-i;
                i_idx=i;
                j_idx=j;
            }
            j++;
        }
    }
    if(res==INT_MIN)
        return 0;
    return res;
}
//krutikas code
int Solution::maximumGap(const vector<int> &A) {
    
    unordered_map<int,int> m;
    int max=0;
    
    for(int i=0;i<A.size();i++)
    {
        m[A[i]]=i;
    }
    sort(m.begin(),m.end());
    iterator it1=m.begin(); 
    iterator it2=m.end()-1;
    while(it1!=m.end())
    {
        if(it2.second-it1.second>max)   //subtract
        {
            max=it2.second-it1.second;
        }
        if(it2==m.begin())
        {
            it1++;
        }
        it2--;
    }
    return max;
}

int main()
{
    vector<int>A={3,5,4,2,6};
    int C=maximumGap(A);
    cout<<C;
}
