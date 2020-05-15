#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

typedef long long ll;
void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
    cout<<endl;
}

vector<vector<int> >threeSum(vector<int> &A) {
    vector<vector<int>>result;
    sort(A.begin(), A.end());
    auto n = A.size();
    if(n<3)
        return result;
    for (auto i = 0; i<n-2; ++i)
    {
        int l = i+1, r = n-1;
        while (l<r)
        {
            long long int sum = ll(A[i]) + ll(A[l]) + ll(A[r]);
           // cout<<A[i]<<" "<<A[l]<<" "<<A[r]<<" :"<<sum<<endl;
            if(sum==0)
            {
                vector<int>temp;
                temp.push_back(A[i]);
                temp.push_back(A[l]);
                temp.push_back(A[r]);
                bool isPresent = find(result.begin(), result.end(), temp) != result.end();
                if(!isPresent)
                    result.push_back(temp);
            }
            if(sum>0)
                --r;
            else
                ++l;
            
        }

    }
    return result;
    
}
int main()
{
    vector<int>A={2147483647 , -2147483648 , -2147483648 , 0 ,1};
    vector<vector<int>>res=threeSum(A);
    for(int i=0;i<res.size();i++)
        print(res[i]);
}