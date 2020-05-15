#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
vector<vector<int>> ans;

void recurse(int cur, int A, vector<int> &bits){
    if(cur == A){
        ans.push_back(bits);
        return;
    }
    if(bits[cur] == 0){
        recurse(cur+1, A, bits);
        bits[cur] = 1;
        recurse(cur+1, A, bits);
    }else {
        recurse(cur+1, A, bits);
        bits[cur] = 0;
        recurse(cur+1, A, bits);
    }
}

vector<int> grayCode(int A) {
    ans = vector<vector<int>> ();
    vector<int> bits(A);
    recurse(0, A, bits);
    vector<int> ans1;
    for(auto it:ans){
        int val = 0, cur = 1;
        for(int i = it.size()-1; i >= 0; i--){
            val += it[i]*cur;
            cur *= 2;
        }
        ans1.push_back(val);
    }
    return ans1;
}
//prabhaths code
/*vector<int> grayCode(int A) {
    vector<int>res;
    for(int i=0;i<pow(2,A);i++)
    {
        cout<<"i : "<<i<<" "<<"i>>1 : "<<(i>>1)<<endl;
        int m=i^(i>>1);
        res.push_back(m);
    }
    return res;
}
*/
int main()
{
    vector<int>ans=grayCode(4);
    print(ans);
}
