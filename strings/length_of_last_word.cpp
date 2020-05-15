#include<iostream>
#include<string>
using namespace std;

int Solution::lengthOfLastWord(const string A) {
    int n=A.size();
    int count=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==' ')
            count=0;
        else
        {
             count++;
             ans=count;
        }

    }
    return ans;
}
//prakritis code
int Solution::lengthOfLastWord(const string A) {
    int len = 0;
    for(int i = A.size()-1 ; i >=0; i--){
        char c = A[i];
        if(isspace(c))
        {
            if(len != 0){
                return len;
            }
            else{
                len = 0;
            }
        }
        else{
            len++;
        }
    }

    return len;
}

int main()
{

}

