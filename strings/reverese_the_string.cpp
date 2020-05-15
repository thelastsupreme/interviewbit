#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void print(std::vector<string> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

string solve(string A) {
    vector < string> sol;
    string temp="";
    for(int i=0;i<A.size();i++)
        {
            temp.push_back(A[i]);
            if(A[i]==' '||i+1==A.size())
                {
                    sol.push_back(temp);
                    temp.clear();
                }

        }
    A.clear();
    if(sol.size()==1)
        {
            A+=sol[0];
            return A;
        }
    for(int i=sol.size()-1;i>=0;i--)
        {
            if(i==sol.size()-1)
            {
                A+=sol[i]+" ";
            }
            else
            A+=sol[i];
        }
int n=A.length();
n=n-1;
A.erase(A.begin()+n);
return A;
}


int main()
{
    string s=solve("the sky is blue");
    cout<<s;
}
