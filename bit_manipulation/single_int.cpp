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
/*int singleNumber(const vector<int> &A) {
    if(A.size()==0) return 0;
    if(A.size()==1) return A[0];
    vector<int> B(A);
    sort(B.begin(),B.end());
    print(B);
    cout<<endl;
    for(int i=0;i<B.size();i++)
    {
        if(i==B.size()-1) return B[i];
        if(B[i]==B[i+1]) i++;
        else return B[i];
    }

}
*/
//prabhaths code
int singleNumber(const vector<int> &A) {
   int temp=A[0];
   for(int i=1;i<A.size();i++)
    {
        temp=temp ^A[i];
        cout<<temp<<" ";
    }

    cout<<endl;
    return temp;
}


int main()
{
    vector<int>A={12,4,6,2};
    int n=singleNumber(A);
    cout<<n;
}
