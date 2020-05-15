#include<iostream>
#include<vector>
#include<algorithm>
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
//initial code
/*vector<vector<int>> diagonal(vector<vector<int> > &A) {
    int n=A.size();
    vector<vector<int>>result(2*n-1,vector<int>(n,0));
   // print_vect(result);
    for(int i=0;i<=2*n-2;i++){
        for(int j=0;j<=i;j++){
            if(j>=n || i-j>=n) continue;
            int k=i-j;
            result[i][j]=A[j][k];
        }
    }
    for(int i=0;i<2*n-1;i++)
    {
        if(i<n)
            result[i].erase(result[i].begin()+i+1,result[i].end());
        if(i>=n)
            result[i].erase(result[i].begin(),result[i].begin()+i-n+1);
    }
   return result;

}
*/
//revision code
vector<vector<int>> diagonal(vector<vector<int> > &A) {
    int n=A.size();
    vector<vector<int>>res(2*n-1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            res[i+j].push_back(A[i][j]);
        }
    }
    return res;
}

/*
krutikas code
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
    
    vector<vector<int>> sol(2*A.size()-1);
    
    for(int i=0;i<A.size();i++)
    {
        int j=i;
        for(int k=0;k<A.size();k++)
        {
            sol[j].push_back(A[i][k]); //
            j++;
        }
    }
    return sol;
}
*/
int main()
{
    vector<vector<int>> A={{1,2,3,4},{5,6,7,8},{8,9,10,11},{12,13,14,15}};
    vector<vector<int>> B=diagonal(A);
    print_vect(B);
}
