#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
void arrange(vector<int> &A) {
    int n=A.size();
    for(int i=0;i<n;i++){
        A[i]=A[i]+(A[A[i]]%n)*n;
    }
    for(int i=0;i<n;i++)
     A[i]=A[i]/n;
   print(A);
}

int main()
{
    vector<int>n={0,2,3,1,4};
    arrange(n);

}
