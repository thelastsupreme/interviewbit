#include<iostream>
#include<vector>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
//prabhaths code
/*void Solution::sortColors(vector<int> &A) {
    //vector int res;
    int zero=count(A.begin(),A.end(),0);
    int one=count(A.begin(),A.end(),1);
    int two=count(A.begin(),A.end(),2);
    A.clear();
    for(int i=0;i<zero;i++)
        A.push_back(0);
    for(int i=0;i<one;i++)
        A.push_back(1);
    for(int i=0;i<two;i++)
        A.push_back(2);
}

//prakritis code
vector<int> sortColors(vector<int> &A)
{
    int ct1 = 0,ct2 = 0 ,ct3=0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]==0)
            ct1++;
        if(A[i]==1)
            ct2++;
        if(A[i]==2)
            ct3++;
    }
    A.clear();
    while(ct1>0)
    {
        A.push_back(0);
        ct1--;
    }
    while(ct2>0)
    {
        A.push_back(1);
        ct2--;
    }
    while(ct3>0)
    {
        A.push_back(2);
        ct3--;
    }
    return A;
}
*/
//krutikas code
void sortColors(vector<int> &A) {
    //vector<int> B(A.size());
    int temp;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==0)
        {   temp=A[i];
            A.erase(A.begin()+i);
            A.insert(A.begin(),A[i]);

        }
        else if(A[i]==2)
        {
            temp=A[i];
            A.erase(A.begin()+i);
            A.push_back(temp);
        }
    }
    print(A);
}

int main()
{
    vector<int>A={1,2,0,2,1,0,2,2,1,1,0};
    sortColors(A);
}
