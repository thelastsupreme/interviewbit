#include<iostream>
#include<string>
#include<vector>
using namespace std;

void print(std::vector<string> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << "\n";
	}
}
//initial logic //krutikas code //best solution
string convert(string A, int B) {
    vector<string> v(B); int count=0; int dir=0;
    string res="";
    if(B==1) return A;
    for(int i=0;i<A.size();i++)
    {
        v[count].push_back(A[i]);
        if(count==B-1)
            dir=1;
        else if(count==0)
            dir=0;
        if(dir==0)
            count++;
        else
            count--;
    }
    for(int i=0;i<B;i++)
      res.append(v[i]);

    return res;

}
//prakritis code using one string
/*string convertt(string A,int B)
{
    if(B==1)
        return A;
    string res="";

    int n=B+B-2;
    for(int i=0;i<B;i++)
    {
        int cur=i;
        while(cur<A.length())
        {
            res.append(A[A.at(cur)]);
            cur+=n;
            if(i>0 && i< B-1 && (cur-i-i) < A.length())
                res.append(A[A.at(cur-i-i)]);
        }
    }
    return res;

}
*/
//prabhath code using one string
/*string convert(string A, int B) {
    string ans="";
    int ele_idx=2*(B-1);
    int j=0;
    bool dir=1;
   // cout<<"ele_index: "<<ele_idx;
    while(ele_idx>=0)
    {
       cout<<"ele_idx:"<<ele_idx<<endl;
        for(j;j<A.size();j+=ele_idx)
            ans+=A[j];
        cout<<ans<<endl;
        j++;
        if(dir==1)
        {
          ele_idx-=2;
          dir==0;
        }
        if(dir==0)
        {
            ele_idx+=2;
        }

    }
    return ans;
}
*/
//best lightweight solution
string Solution::convert(string A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i,j,k,n=A.length(),a,b,x=0;
    if(B>=n || B==1) return A;
    k=(B-1)*2;
    a=k; b=0;
    string ans=A;
    for(i=0;i<B;i++){
        ans[x++]=A[i];
    //    cout<<ans[x-1];
        j=i;
        while(j<n){
            if(a==0) j+=k;
            else j+=a;
            if(j>=n) break;
            else ans[x++]=A[j];
      //      cout<<ans[x-1];
            if(b==0) j+=k;
            else j+=b;
            if(j>=n) break;
            else ans[x++]=A[j];
        //    cout<<ans[x-1];
        }
        a-=2;
        b+=2;
    }
    //ans[n]='\0';
    return ans;
}

int main()
{
    string s=convert("paypalishiring",3);
    cout<<s;
}
