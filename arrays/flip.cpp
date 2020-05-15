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

vector<int> flip(string A) {
    int n=A.size();
    int t1=count(A.begin(),A.end(),'1');
    vector<int>res;
    int q=0,w=0;
    int z=0,o1=0,o2=0;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
           // cout<<"i:"<<i<<"j:"<<j<<endl;
            string s0=A.substr(0,i);
           // cout<<"s0 : "<<s0<<endl;
            string s1=A.substr(i,j-i+1);
           // cout<<"s1 : "<<s1<<endl;
            string s2=A.substr(j+1,n-j);
           // cout<<"s2 : "<<s2<<endl;
            o1=count(s0.begin(),s0.end(),'1');
           // cout<<o1<<endl;
            z=count(s1.begin(),s1.end(),'0');
           // cout<<z<<endl;
            o2=count(s2.begin(),s2.end(),'1');
           //cout<<o2<<endl;
            if(o1+z+o2>t1)
            {
                t1=o1+z+o2;
                q=i+1;
                w=j+1;
                flag=1;
               // cout<<"q :"<<q<<endl;
               // cout<<"w:"<<w<<endl;
            }
        }
    }
    if(flag==0)
      return res;
    else
    {
        res.push_back(q);
        res.push_back(w);
        return res;
    }

}
///////////////most efficient ////////////////////
//kadanes algorithm
vector<int>flip(string A) {
    vector<int> ZeroOrOne(A.size()); // if zero then 1, if one then -1.
    vector<int> ans;

    for(int i = 0; i<A.size(); i++){
        if(A[i]=='0')
            ZeroOrOne[i] = 1;

        else
            ZeroOrOne[i] = -1;
    }

    int cumulative=0, left=0, right=0, maxSum=INT_MIN;
    int leftAns=0, rightAns=0;

    for(int i=0; i<A.size(); i++){
        cumulative+=ZeroOrOne[i];

        if(cumulative<0){
            left=i+1;
            cumulative=0;
        }

        else if(cumulative>maxSum){
            leftAns = left;
            rightAns = i;
            maxSum=cumulative;
        }
    }

    if(maxSum<=0){
        return ans;
    }

    else{
        ans.push_back(leftAns+1);
        ans.push_back(rightAns+1);
    }

    return ans;
}


int main()
{
    string s="100101";
    vector<int>v=flip(s);
    print(v);
}

