// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

// You may assume that the intervals were initially sorted according to their start times.

// Example 1:

// Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

// Example 2:

// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

// Make sure the returned intervals are also sorted.

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
void print(vector<Interval*>input)
{
	for (int i = 0; i < input.size(); i++) {
		cout<<input[i]->start<<" ";
        cout<<input[i]->end<<endl;
	}
}


// vector<Interval> inssert(vector<Interval> &intervals, Interval newInterval) {
//    int n=intervals.size();
//     vector<Interval>res;
//     if(n==0)
//         {
//             res.push_back(newInterval);
//             return res;
//         }
//     if(newInterval.end<intervals[0].start)
//         res.push_back(newInterval);
//     for(int i=0;i<n;i++)
//     {   if(((newInterval.start>intervals[i].end)&&(newInterval.end>intervals[i].end))&&((newInterval.start<intervals[i+1].end)&&(newInterval.end<intervals[i+1].end)))
//            res.push_back(newInterval);

//         else if((newInterval.start>intervals[i].start)&&(newInterval.start<intervals[i].end))
//         {
//             Interval x;
//             x.start=intervals[i].start;
//             for(int j=i+1;j<n;j++)
//             {
//                 if((newInterval.end<intervals[j].end)&&(newInterval.end>intervals[j].start))
//                     x.end=intervals[j].end;
//             }
//             res.push_back(x);
//         }
//         else if((intervals[i].start>newInterval.end)||(intervals[i].end<newInterval.start))
//             res.push_back(intervals[i]);
//     }
//     if(newInterval.start>intervals[n-1].end)
//         res.push_back(newInterval);
//     return res;
// }

//logic : push the nbew interval and sort based on start time for all the intervals
//now take a new op vector and compare start time of element in curr vector and end time of last 
//inserted interval in op vector
bool mycomp(Interval* a,Interval* b){
     return a->start<b->start;
}
//changed code to effectively work for pointers
vector<Interval*> insert(vector<Interval*> &A, Interval* newInterval) {
    A.push_back(newInterval);
    sort(A.begin(),A.end(),mycomp);
    vector<Interval*> res;
    int n=A.size();
    res.push_back(A[0]);
    for(int i=1;i<n;i++){
        if(A[i]->start<=res[res.size()-1]->end)
         res[res.size()-1]->end=max(res[res.size()-1]->end,A[i]->end);
        else
         res.push_back(A[i]);
    }
    return res;
}

//krutikas code
//yet to be coded completely but awesome logic
// vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    
//     int n=intervals[intervals.size()-1].end;
//     vector<int> countt(n);
//     vector<Interval> solution;
//     intervals.push_back(newInterval);
//     for(int i=0;i<intervals.size();i++)
//     {
//         int begin=intervals[i].start;
//         int en=intervals[i].end;
//         for(int j=begin;j<=en;j++)
//             countt[j]=1;
//     }
//     int stime=0,etime=0;
//     for(int i=1;i<countt.size();i++)
//     {
//         if(countt[i]==0)
//         {
//             endtime=i-1;
//             Interval in;
//             in.start=stime;
//             in.end=etime;
//             if(find(solution.begin(),solution.end(),in)==solution.end())
//             {
//                 solution.push_back(in);
//             }
//         }
//     }
// }

int main()
{
    Interval* A=new Interval(1,2);
    Interval* B=new Interval(3,5);
    Interval* C=new Interval(6,7);
    Interval* D=new Interval(8,10);
    Interval* E=new Interval(12,16);

    Interval* F=new Interval(4,9);
    vector<Interval*>res;
    res.push_back(A);
    res.push_back(B);
    res.push_back(C);
    res.push_back(D);
    res.push_back(E);

    vector<Interval*>ans=insert(res,F);
    print(ans);

}
