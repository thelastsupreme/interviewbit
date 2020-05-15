#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;
//solution from comments
/*int Solution::maxPoints(vector<int> &A, vector<int> &B)
{
    if(A.size()==0)
        return 0;

     int overall_max = 0;
     unordered_map<double,int> map;
     int N=A.size();

     for(int i=0;i<N;i++)
     {
        for(int j=0;j<N;j++)
        {
             if(i!=j)
             {
                 int x = A[i];
                 int y = B[i];
                 int temp_x = A[j];
                 int temp_y = B[j];
                 if((temp_x-x)==0)
                 {
                     map[INT_MAX]++;
                 }
                 else
                 {
                     double slope =  (temp_y-y)/((temp_x-x)*1.0);
                     map[slope]++;
                 }
             }
       }
    for(auto i:map)
    {
          if(i.second>overall_max)
          overall_max = i.second;
    }
    map.clear();
    }
 return overall_max+1;
}
*/
//prabhaths code

void print(vector<pair<double,int>> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i).first << "->"<<input.at(i).second<<endl;;
	}
}
bool sortByVal(const pair<double, int> &a,
               const pair<double, int> &b)
{
    return (a.second > b.second);
}

int maxPoints(vector<int> &A, vector<int> &B) {
    if(A.size()==0||A.size()==1)
        return A.size();
    unordered_map<double,int>m;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A.size();j++)
        {
            if(i!=j)
            {
                int x1=A[i];
                int y1=B[i];
                int x2=A[j];
                int y2=B[j];
                if(x1==x2)
                    m[INT_MAX]++;
                else
                {
                    cout<<"p1 : "<<x1<<y1<<" "<<"p2 : "<<x2<<y2<<endl;
                    double slope=((y2-y1)/(x2-x1)*1.0);
                    cout<<"slope : "<<slope<<endl;
                    m[slope]++;
                }
            }

        }

    }
    vector<pair<double, int>> vec;
    unordered_map<double, int> :: iterator it;
    for (it=m.begin(); it!=m.end(); it++)
    {
        vec.push_back(make_pair(it->first, it->second));
    }
    sort(vec.begin(),vec.end(),sortByVal);
    print(vec);
    if(vec[0].first==INT_MAX)
        return vec[0].second;
    return vec[0].second;

}
int main()
{
    vector<int>A={0,1,-1};
    vector<int>B={0,1,-1};
    int n=maxPoints(A,B);
    cout<<"max points on the line are : "<<n;
}