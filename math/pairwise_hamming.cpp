#include<iostream>
#include<vector>
#include<math.h>
#include<string>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
/*string findDigitsInBinary(int A) {
    if(A==0)
        return to_string(0);
    string ress;
    vector<int>res;
    int rem=1;
    while(A>0)
    {
        rem=A%2;
        res.push_back(rem);
        A/=2;
    }
    reverse(res.begin(),res.end());
    for(int i=0;i<res.size();i++)
        ress+=to_string(res[i]);
    return ress;
}
*/
int Solution::hammingDistance(const vector<int> &A) {
    long long int res=0,
    int n=A.size();
    long long int count;
    for(int i=0;i<31;i++){
        count=0;
        for(int j=0;j<n;j++){
            if(A[j]&(1<<i)) //check if there is a bit match
             count++;       //increment count for that digit
        }
        res=(res+count*(n-count)*2); //count of matching *not matching *2(since twice )
    }
    return res%1000000007;
}
