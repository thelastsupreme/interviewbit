#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
//krutikas code
void Solution::rotate(vector<vector<int> > &A) {

    vector<vector<int>> B(A);
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A.size();j++)
        {
            B[j][i]=A[i][j];
        }
    }
    for(int i;i<B.size();i++)
        reverse(B[i].begin(),B[i].end());

    A=B;
}
//prabhaths code
void rotatee(vector<vector<int> > &A) {
    for(int i=0;i<A.size();i++)
    {
        for(int j=i;j<A[0].size();j++)
            swap(A[i][j],A[j][i]);
    }
    for(int i=0;i<A.size();i++)
        reverse(A[i].begin(),A[i].end());
}
//prakritis code
void rotate(vector<vector<int> > &matrix) {
    int len = matrix.size();
    for (int i = 0; i < len / 2; i++) {
        for (int j = i; j < len - i - 1; j++) {
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
    rotatee(A);
}
