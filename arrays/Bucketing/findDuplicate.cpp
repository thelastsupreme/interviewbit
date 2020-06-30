//Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

// Sample Input:

// [3 4 1 4 1]
// Sample Output:

// 1
// If there are multiple possible answers ( like in the sample case above ), output any one.

// If there is no duplicate, output -1

#include<iostream>
#include<vector>
using namespace std;

//logic : simply try and store the first occureneces somehow
int repeatedNumber(const vector<int> &A) {
    
    vector <bool> v(A.size());  //a vector of flags set to true
    fill(v.begin(), v.end(), true);

    for(int i=0;i<A.size();i++){
        if(v[A[i]]){           //if u encounter element set its flag to false
            v[A[i]]=false;
        }
        else                  //if u encounter a false flag just return it
            return A[i];
    }
}
int main(){
    vector<int>A={3,4,1,4,1};
    cout<<repeatedNumber(A);
}
