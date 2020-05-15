#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
//online code
/*int Solution::compareVersion(string A, string B) {
    int i = 0, j = 0;

    while(i<A.length() && j<A.length()){
        string x="";
        string y="";

        while(i<A.length() && A[i]=='0'){
                i++;
        }

        while(i<A.length() && A[i]!='.'){
            x+=A[i];
            i++;
        }

        while(j<B.length() && B[j]=='0'){
                j++;
        }

        while(j<B.length() && B[j]!='.'){
            y+=B[j];
            j++;
        }

        if(x!=y){
            if(x.length()==y.length())
                return x.compare(y) > 0 ? 1: -1;
            return x.length()>y.length() ? 1:-1;
        }

        i++;
        j++;
    }

    while(i<A.length() && A[i]=='0'){
        i++;
    }

    while(j<B.length() && B[j]=='0'){
        j++;
    }

    if(i>=A.length() && j>=B.length())
        return 0;

    return i>j ? 1 : -1;
}
*/
int compareVersion(string A, string B) {
    if(A==B)
        return 0;
    int a=A.size();
    int b=B.size();
  //  int dot_a=count(A.begin(),A.end(),'.');
  //  int dot_b=count(B.begin(),B.end(),'.');
   /* vector<int>a1(dot_a);
    vector<int>b1(dot_b);
    for(int i=0;i<a;i++)
        if(A[i]!='.')
            a1.push_back(A[i]-'0');
    for(int i=0;i<b;i++)
        if(B[i]!='.')
            b1.push_back(B[i]-'0');
    print(a1);
    cout<<endl;
    print(b1);
    */
    int n=min(a,b);

    for(int i=0;i<n;i++)
    {
        if(A[i]==B[i])
            continue;
        else if(A[i]<B[i])
            return -1;
        else if(A[i]>B[i])
            return 1;
    }
    if(n==a)
        return -1;
    if(n==b)
        return 1;

}

int main()
{
 string a = "10.04.1";
 string b=  "10.4.1";
 int n=compareVersion(a,b);
 cout<<n;
}

