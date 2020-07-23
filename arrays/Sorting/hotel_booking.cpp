// A hotel manager has to process N advance bookings of rooms for the next season. His hotel has C rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .



// Input Format
// First argument is an integer array A containing arrival time of booking.
// Second argument is an integer array B containing departure time of booking.
// Third argument is an integer C denoting the count of rooms.



// Output Format
// Return True if there are enough rooms for N bookings else return False.
// Return 0/1 for C programs.



// Example Input
// Input 1:

//  A = [1, 3, 5]
//  B = [2, 6, 8]
//  C = 1


// Example Output
// Output 1:

//  0


// Example Explanation
// Explanation 1:

//  At day = 5, there are 2 guests in the hotel. But I have only one room.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//inital logic was to sort based on arrival time
//then run a loop on variable t for every second and check in how many intervals does t lie in
//and decrement j which stores the value of rooms
//if at any point you decrement more than the room you have then return -1
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

//editorial solution 
//assign all arrival time value of 1
//assign all departure time value of -1
//sort based on their times
//at any point the number of 1s exceed -1s by k return -false
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
    bool l=hotel(A,B,2);
    cout<<l;
}
