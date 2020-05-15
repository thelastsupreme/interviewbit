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

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

vector<Interval> inssert(vector<Interval> &intervals, Interval newInterval) {
   int n=intervals.size();
    vector<Interval>res;
    if(n==0)
        {
            res.push_back(newInterval);
            return res;
        }
    if(newInterval.end<intervals[0].start)
        res.push_back(newInterval);
    for(int i=0;i<n;i++)
    {   if(((newInterval.start>intervals[i].end)&&(newInterval.end>intervals[i].end))&&((newInterval.start<intervals[i+1].end)&&(newInterval.end<intervals[i+1].end)))
           res.push_back(newInterval);

        else if((newInterval.start>intervals[i].start)&&(newInterval.start<intervals[i].end))
        {
            Interval x;
            x.start=intervals[i].start;
            for(int j=i+1;j<n;j++)
            {
                if((newInterval.end<intervals[j].end)&&(newInterval.end>intervals[j].start))
                    x.end=intervals[j].end;
            }
            res.push_back(x);
        }
        else if((intervals[i].start>newInterval.end)||(intervals[i].end<newInterval.start))
            res.push_back(intervals[i]);
    }
    if(newInterval.start>intervals[n-1].end)
        res.push_back(newInterval);
    return res;
}
//prakritis code
bool mycomp(Interval a,Interval b){
     return a.start<b.start;
 }
vector<Interval> insert(vector<Interval> &A, Interval newInterval) {
    A.push_back(newInterval);
    sort(A.begin(),A.end(),mycomp);
    vector<Interval> res;
    int n=A.size();
    res.push_back(A[0]);
    for(int i=1;i<n;i++){
        if(A[i].start<=res[res.size()-1].end)
         res[res.size()-1].end=max(res[res.size()-1].end,A[i].end);
        else
         res.push_back(A[i]);
    }
    return res;
}
//krutikas code
//yet to be coded completely but awesome logic
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    
    int n=intervals[intervals.size()-1].end;
    vector<int> countt(n);
    vector<Interval> solution;
    intervals.push_back(newInterval);
    for(int i=0;i<intervals.size();i++)
    {
        int begin=intervals[i].start;
        int en=intervals[i].end;
        for(int j=begin;j<=en;j++)
            countt[j]=1;
    }
    int stime=0,etime=0;
    for(int i=1;i<countt.size();i++)
    {
        if(countt[i]==0)
        {
            endtime=i-1;
            Interval in;
            in.start=stime;
            in.end=etime;
            if(find(solution.begin(),solution.end(),in)==solution.end())
            {
                solution.push_back(in);
            }
        }
    }
}

int main()
{
    
    //setZeroes(C);
    //print_vect(B);
}
