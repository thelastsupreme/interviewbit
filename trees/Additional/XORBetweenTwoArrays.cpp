// Given two integer array A and B, you have to pick one element from each array such that their xor is maximum.

// Return this maximum xor value.



// Problem Constraints
// 1 <= |A|, |B| <= 105

// 1 <= A[i], B[i] <= 109



// Input Format
// First argument is an integer array A.

// Second argument is an integer array B.



// Output Format
// Return an integer denoting the maximum xor value as described in the question.



// Example Input
// Input 1:

//  A = [1, 2, 3]
//  B = [4, 1, 2]


// Example Output
// Output 1:

//  7


// Example Explanation
// Explanation 1:

//  Pick A[2] and B[0] because their xor value is maximum. 3 ^ 4 = 7
#include <bits/stdc++.h>
using namespace std;


void print(vector<pair<int,int>>A)
{
    for(int i=0;i<A.size();i++)
    {
        cout<<A[i].first<<" "<<A[i].second<<endl;
    }
    cout<<endl;
}
void print_vector(vector<int>A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

// int solve(vector<int> &A, vector<int> &B) {
//     vector<pair<int,int>>A1;
//     vector<pair<int,int>>B1;
    
//     for(int i=0;i<A.size();i++)
//         A1.push_back(make_pair(A[i],0));
//     for(int i=0;i<B.size();i++)
//         B1.push_back(make_pair(B[i],1));
    
//     A1.insert(A1.end(),B1.begin(),B1.end());
//     sort(A1.begin(),A1.end());
//     print(A1);
//     int temp;
//     int res=INT_MIN;
//     for(int i=0;i<A1.size()-1;i++)
//     {
//         if(A1[i].second!=A1[i+1].second)
//         {
//             temp=A1[i].first^A1[i+1].first;
//             res=max(res,temp);
//         }
        
//     }
//     return res;
// }

//Editorial using tries
struct tri{
  int leaf=0;
  tri*next[2];
  tri(){
      next[0]=next[1]=NULL;
  }
};
int solve(vector<int> &A, vector<int> &B) {
 tri*head=new tri();
 for(int i=0;i<A.size();i++){
     tri*temp=head;
     for(int j=31;j>=0;j--){
         int x=(A[i]>>j)&1;
         if(temp->next[x]==NULL)
         temp->next[x]=new tri();
         temp=temp->next[x];
     }
     temp->leaf=i;
 }  int ans=0;
 for(int i=0;i<B.size();i++){
       tri *temp=head; int xo=0;
       for(int j=31;j>=0;j--){
           int x=(B[i]>>j)&1;
           if(temp->next[x^1]!=NULL){
               temp=temp->next[x^1];
               xo|=(1<<j);
           }
           else{
               temp=temp->next[x];
           }
       }
       ans=max(ans,xo);
 }
 return ans;
    
}


int main()
{
    vector<int>A={1,2,3};
    vector<int>B={4,1,2};
    cout<<solve(A,B);
}