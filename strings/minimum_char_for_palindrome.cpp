#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string str){
 int len = str.length();
    for(int i = 0; i < len/2; i++){
        if(str[i] != str[len-1-i]){
            return false;
        }
    }
    return true;
}
int Solution::solve(string A) {
    int n=A.size();
    int lenn=0;
    if(n==1)
        return 0;

    for (int i = 0; i < n; i++)
       {
           for (int len = 1; len <= n - i; len++)
           {
               string a=A.substr(i, len);

               if(isPalindrome(a)&&(len>lenn))
                    lenn=len;

           }
       }
    return n-lenn;

}
//approach using is_palindrome function
int solve(string A)
{
   // reverse(A.begin(), A.end());
    int count = 0;
    while(A.size() > 1)
    {
        if(is_palindrome(A))
        {
            return count;
        }
        A.pop_back();
        count++;
    }
    return count;
}
//better approach
int Solution::solve (string A) {
    int start = 0, end = A.length() - 1, rec = A.length () - 1;
    while (start < end) {
        if (A [start] == A [end]) {
            start ++;
            end --;
        } else {
            start = 0;
            rec --;
            end = rec;
        }
    }
    return A.length () - rec - 1;
}
int main()
{
    string abc= "babb";
    int out= solve(abc);
    cout<<"Ans is: "<<out<<"\n";
}
/////if insertion only from front/////////////
int Solution::solve(string A) {
    int n = A.size(), match = 1;

    if(n == 0){
        return 0;
    }

    for(int i = 1; i < n; i++){
        int start = 0, end = i, pal = 1;
        while(start < end){
            if(A[start] != A[end]){
                pal = 0;
                break;
            }
            start++;
            end--;
        }

        if(pal){
            match = i + 1;
        }
    }

    return n - match;
}
