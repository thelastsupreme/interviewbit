// Given a non-negative number represented as an array of digits,

// add 1 to the number ( increment the number represented by the digits ).

// The digits are stored such that the most significant digit is at the head of the list.

// Example:

// If the vector has [1, 2, 3]

// the returned vector should be [1, 2, 4]

// as 123 + 1 = 124.

//  NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
// For example, for this problem, following are some good questions to ask :
// Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
// A : For the purpose of this question, YES
// Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
// A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

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

//logic:is just basic iteration and trying to carry the sum but you need to conisder cases when digit 9 occurs
//go through krutikas code it is very optimized and compact

//krutikas code
vector<int> plusOne_K(vector<int> &A) {
    vector<int> result;  //declare vector for op
    int n=A.size();

    int carry=1; int sum=0;  //taking carry 1 cause we need to add one as the question says
    for(int i=A.size()-1;i>=0;i--)
    {
        sum=A[i]+carry;
        if(sum==10)   //only two digit case is 10 push 0 carry 1
        {
            result.push_back(0); carry=1;
        }
        else
        {
            result.push_back(sum);
            carry=0;  //reset carry to zero
        }

    }
    if(carry) //if carry 1 is left add it to vector
    result.push_back(carry);

    reverse(result.begin(),result.end());//reverse it
    int count=0;  //to count number of zeros before our digits start
    for(int j=0;j<result.size()-1;j++)
      if(result[j]==0) count++;
      else break;
    result.erase(result.begin(),result.begin()+count);//erase all 0s preceeding cuase the note mentions it
    return result;
}

//prabhaths code
vector<int> plusOne(vector<int> &A) {
    vector<int>B;
    int n=A.size();
    int flag=1;
    int k=1;
    int count=0;
    for(int i=0;i<n;i++)
    {    if(A[i]!=9)
           {
            flag=0;
            break;
           }
         else
            flag=1;
    }

    if(flag==1)
    {   B.push_back(1);
        for(int i=0;i<n;i++)
            B.push_back(0);
    }
    else if(flag==0)
    {   for(int i=0;i<n;i++)
           {
            B.push_back(A[i]);
           }
            if(A[n-1]+1>9)
            {
                B[n-2]++;
                B[n-1]=0;
            }
            else
                {B[n-1]++;k=0;}
        for(int i=n-2;i>0;i--)
        {
             if((A[i]+1>9)&&(A[i+1]==9)&&(k==1))
                {
                    B[i-1]++;
                   // cout<<B[i-1];
                    B[i]=0;
                }
            if(A[i]!=9)
                k=0;
        }
    }


    for(int i=0;i<n;i++)
    {
        if(B[i]==0)
            count++;
        else break;
    }
    B.erase(B.begin(),B.begin()+count);
    return B;
}

int main()
{
    vector<int> A={0,9,8,9,1};
    vector<int>B;
    B=plusOne_K(A);
    vector<int>C=plusOne(A);
    print(B);
    cout<<endl;
    print(C);
}
