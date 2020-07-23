// Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].



// Input Format
// First and only argument is an integer array A.



// Output Format
// Return an integer denoting the maximum value of j - i;



// Example Input
// Input 1:

//  A = [3, 5, 4, 2]


// Example Output
// Output 1:

//  2


// Example Explanation
// Explanation 1:

//  Maximum value occurs for pair (3, 4).

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
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

//store a vector of pair of numbers and their indices
int maximumGap(const vector<int> &A) {
    int n=A.size();
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(A[i],i));
    }
    sort(v.begin(),v.end());  //now no need to worry about second constraint just find max diff
    int ans=0;
    int rmax=v[n-1].second;
    for(int i=n-2;i>=0;i--){  
        ans=max(ans,rmax-v[i].second);
        rmax=max(rmax,v[i].second);
    }
    return ans;
}
//best approach
int maximumGap_best(const vector<int> &a) {
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

//krutikas code
// int maximumGap_2(const vector<int> &A) {
    
//     unordered_map<int,int> m;
//     int max=0;
    
//     for(int i=0;i<A.size();i++)
//     {
//         m[A[i]]=i;
//     }
//     sort(m.begin(),m.end());
//     iterator it1=m.begin(); 
//     iterator it2=m.end()-1;
//     while(it1!=m.end())
//     {
//         if(it2.second-it1.second>max)   //subtract
//         {
//             max=it2.second-it1.second;
//         }
//         if(it2==m.begin())
//         {
//             it1++;
//         }
//         it2--;
//     }
//     return max;
// }

int main()
{
    vector<int>A={3,5,4,2,6};
    int C=maximumGap(A);
    cout<<C;
}
