#include<iostream>
#include<string>
using namespace std;

int value(char c){
    if(c == 'I'){
        return 1;
    }
    else if(c == 'V'){
        return 5;
    }
    else if(c == 'X'){
        return 10;
    }
    else if(c == 'L'){
        return 50;
    }
    else if(c == 'C'){
        return 100;
    }
    else if(c == 'D'){
        return 500;
    }
    else{
        return 1000;
    }
}

int Solution::romanToInt(string A) {
    int n=A.size();
    int res=0;
    for(int i=0;i<n;i++)
        {
            res+=value(A[i]);
            if(i>0 &&value(A[i])>value(A[i-1]))
                res=res-2*value(A[i-1]);
        }
        return res;
}
