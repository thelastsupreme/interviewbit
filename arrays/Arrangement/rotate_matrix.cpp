// You are given an n x n 2D matrix representing an image.

// Rotate the image by 90 degrees (clockwise).

// You need to do this in place.

// Note that if you end up using an additional array, you will only receive partial score.

// Example:

// If the array is

// [
//     [1, 2],
//     [3, 4]
// ]
// Then the rotated array becomes:

// [
//     [3, 1],
//     [4, 2]
// ]

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//logic here is to just take a transpose and reverse each row after it
//krutikas code
void rotate_K(vector<vector<int> > &A) {

    vector<vector<int>> B(A); //no need to use additional space try to change A directly
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A.size();j++)
        {
            B[j][i]=A[i][j];   //transpose from index 0 cause new insertion of elements
        }
    }
    for(int i;i<B.size();i++)
        reverse(B[i].begin(),B[i].end());

    A=B;
}

//prabhaths code
void rotate(vector<vector<int> > &A) {
    for(int i=0;i<A.size();i++)
    {
        for(int j=i;j<A[0].size();j++)
            swap(A[i][j],A[j][i]);  //transpose from j=i is optimized
    }
    for(int i=0;i<A.size();i++)
        reverse(A[i].begin(),A[i].end()); //stl reverse
}

//prakritis code
void rotate_P(vector<vector<int> > &matrix) {
    int len = matrix.size();
    for (int i = 0; i < len / 2; i++) {
        for (int j = i; j < len - i - 1; j++) { //or identify all the swaps and perform in a loop
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[len - j - 1][i];
        matrix[len - j - 1][i] = matrix[len - i - 1][len - j - 1];
        matrix[len - i - 1][len - j - 1] = matrix[j][len - i - 1];
        matrix[j][len - i - 1] = tmp;
        }
    }
}
int main()
{
    vector<vector<int>>A={{1,2},{3,4}};
    rotate(A);
    for (int i = 0; i < A.size(); i++)
    {
        for(int j=0;j<A[i].size();j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
