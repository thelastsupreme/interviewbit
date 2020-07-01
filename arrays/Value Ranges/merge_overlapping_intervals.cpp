// Given a collection of intervals, merge all overlapping intervals.

// For example:

// Given [1,3],[2,6],[8,10],[15,18],

// return [1,6],[8,10],[15,18].

// Make sure the returned intervals are sorted.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };


void print(vector<Interval>input)
{
	for (int i = 0; i < input.size(); i++) {
		cout<<input[i].start<<" ";
        cout<<input[i].end<<endl;
	}
}
bool mycomp(Interval a,Interval b){
     return a.start<b.start;
}
//logic : sort based on start time for all the intervals
//now take a new op vector and compare start time of element in curr vector and end time of last 
//inserted interval in op vector
//changed code to effectively work for pointers

vector<Interval> merge(vector<Interval> &A) {
   // A.push_back(newInterval);
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
int main()
{
    Interval A=Interval(1,3);
    Interval B=Interval(2,6);
    Interval C=Interval(8,10);
    Interval D= Interval(15,18);

    vector<Interval>res;
    res.push_back(A);
    res.push_back(B);
    res.push_back(C);
    res.push_back(D);

    vector<Interval>ans=merge(res);
    print(ans);

}
