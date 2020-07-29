// You are climbing a stair case and it takes A steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Input Format:

// The first and the only argument contains an integer A, the number of steps.
// Output Format:

// Return an integer, representing the number of ways to reach the top.

// Constrains:

// 1 <= A <= 36
#include<iostream>
#include<vector>
using namespace std;


//recursive approach
int climbStairs(int Steps){
    if(Steps==1){
        return 1;
    }if (Steps==2)
    {
        return 2;
    }else{
        return climbStairs(Steps-1)+climbStairs(Steps-2);
    }
}

//iterative approach
int climbStarirsIterative(int Steps){
    vector<int>values(Steps+1);
    values[0]=1;
    values[1]=1;
    for(int i=2;i<=Steps;i++){
        values[i]=values[i-1]+values[i-2];
    }
    return values[Steps];
}

int main(){
    cout<<climbStairs(10)<<endl;
    cout<<climbStarirsIterative(10);
}