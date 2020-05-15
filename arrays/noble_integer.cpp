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
//Initial idea
/*int Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<int>count(n,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            {
                if(A[j]>A[i])
                count[i]++;
            }
    }
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(count[i]==A[i])
            {
                flag=1;
                break;
            }

    }
    if(flag==1)
        return 1;
    else
        return -1;
}
*/
// cannot be used cause duplicates add a value too
int solve(vector<int> &A) {
    int n=A.size();
    //cout<<n;
    sort(A.begin(),A.end());
    A.erase(unique(A.begin(), A.end()),A.end());
    print(A);
    int m=A.size();
   for(int i=0;i<m;i++)
   {
       if(A[i]==m-1-i)
        return 1;
   }
   return -1;

}
//final logic
/*int Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<int>count(n,0);
    sort(A.begin(),A.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] == A[i + 1])
            continue;

        if (A[i] == n - i - 1)
            return 1;
    }
    if (A[n - 1] == 0)
        return 1;
    return -1;
}
*/
int main()
{
    vector<int> A={1, 2, 7, 0, 9, 3, 6, 0, 6 };
    int B=solve(A);
    cout<<endl<<B;
}
