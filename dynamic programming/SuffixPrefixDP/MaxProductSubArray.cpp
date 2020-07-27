// Find the contiguous subarray within an array (containing at least one number) which has the largest product.
// Return an integer corresponding to the maximum product possible.

// Example :

// Input : [2, 3, -2, 4]
// Return : 6 

// Possible with [2, 3]

#include <bits/stdc++.h>
using namespace std;

int maxProduct(const vector<int> &A) {
    int maxval=A[0],minval=A[0],max_prod=A[0];
    for(int i=1;i<A.size();i++)
    {
        if(A[i]<0) swap(maxval,minval); //if negative num exchange min and max
        maxval=max(A[i],maxval*A[i]);
        minval=min(A[i],minval*A[i]);
        max_prod=max(max_prod,maxval);
        // cout<<"max_val : "<<maxval<<endl;
        // cout<<"min_val : "<<minval<<endl;
        // cout<<"max_prodcut : "<<max_prod<<endl;
    }
    return max_prod;
}

int main()
{
    vector<int>A={2,3,-2,4};
    cout<<maxProduct(A);
}