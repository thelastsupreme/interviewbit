#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
//instead of this run the for loop in reverse and then u neef to worry about skipping indices
int removeDuplicates(vector<int> &A) {
            int n=A.size();
            int countt=0;
           for (int i = 0; i < n; i++) {
                if (i < n - 2 && A[i] == A[i+1] && A[i] == A[i+2]) continue;
                else {
                    A[countt] = A[i];
                    countt++;
                }
            }
            A.resize(countt);
            print(A);
            cout<<endl;
            return countt;
}

int main()
{
    double n;
    n=-1-0/-1-0;
    cout<<n;
}
