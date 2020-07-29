// Given a 2D matrix, find the number non-empty sub matrices, such that the sum of the elements inside the sub matrix is equal to 0. (note: elements might be negative).

// Example:

// Input

// -8 5  7
// 3  7 -8
// 5 -8  9
// Output
// 2

// Explanation
// -8 
//  3 
//  5 

// 
//  7 -8
// -8  9

#include <bits/stdc++.h>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
    cout<<endl;
}

void print_map(unordered_map<int,int>&map)
{
    auto it=map.begin();
    while(it!=map.end())
    {
        cout<<it->first<<" --> "<<it->second<<endl;
        it++;
    }
}
int help(vector<int> &B)
{
    int n = B.size();
    vector<int> A(n);
    A[0] = B[0];
    for (int i = 1; i < n; i++)
        A[i] = A[i - 1] + B[i];
    // print(A);
    int ans = 0;
    unordered_map<int, int> um;
    um[0] = 1;
    // print_map(um);
    for (int i = 0; i < n; i++)
    {
        ans += um[A[i]];//so if a zero is encountered ans would be increment
                        //or if any value is repeating it means a 0 occured
        um[A[i]]++;
    }
    // print_map(um);
    return ans;
}

int solve(vector<vector<int>> &A)
{
    int row = A.size();
    if (!row)
        return 0;
    int col = A[0].size();
    if (!col)
        return 0;
    int ans = 0;

    for (int U = 0; U < row; U++)
    {
        vector<int> temp(col, 0);
        for (int D = U; D < row; D++)
        {
            for (int i = 0; i < col; i++)
                temp[i] += A[D][i];
            // print(temp);
            ans += help(temp);
            // cout<<"D : "<<D<<" ans : "<<ans<<endl;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> A = {{-8,5,7},{3,7,-8},{5,-8,9}};
    cout<<solve(A);
    // vector<int>B={0,4,8};
    // cout<<help(B);
}