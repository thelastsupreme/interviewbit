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
int gcd(int A, int B) {
    if (A == 0)
       return B;
    if (B == 0)
       return A;
    if (A == B)
        return A;
    if (A > B)
        return gcd(A-B, B);
    return gcd(A, B-A);
}
/*
int cpFact(int A, int B) {
    vector<int>large_B;
    vector<int>large_A;
    vector<int>common;
    for(int i=1;i<=A;i++)
    {
        if(gcd(i,B)==1)
            large_B.push_back(i);
    }
    for(int i=1;i<=A;i++)
    {
        if(A%i==0)
            large_A.push_back(i);
    }
    print(large_A);
    cout<<"\n";
    print(large_B);
    cout<<"\n";
    for(int i=0;i<large_A.size();i++)
    {
        for(int j=0;j<large_B.size();j++)
            if(large_A[i]==large_B[j])
                common.push_back(large_B[j]);
    }
    print(common);
    cout<<"\n";
    return common[common.size()-1];

}
*/
//best approach
int cpFact(int A, int B) {
    while(gcd(A,B)!=1){
        A=A/gcd(A,B);
    }
    return A;
}
int main()
{
    //cout<<gcd(30,12);
    int n=cpFact(21,18);
    cout<<n;
}
