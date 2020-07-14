// Given an expression, A, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?

// Operands are only true and false.

// Return the number of ways to evaluate the expression modulo 103 + 3.



// Input Format:

// The first and the only argument of input will contain a string, A.

// The string A, may contain these characters:
//     '|' will represent or operator 
//     '&' will represent and operator
//     '^' will represent xor operator
//     'T' will represent true operand
//     'F' will false
// Output:

// Return an integer, representing the number of ways to evaluate the string.
// Constraints:

// 1 <= length(A) <= 150
// Example:

// Input 1:
//     A = "T|F"

// Output 1:
//     1

// Explanation 1:
//     The only way to evaluate the expression is:
//         => (T|F) = T 

// Input 2:
//     A = "T^T^F"
    
// Output 2:
//     0
    
// Explanation 2:
//     There is no way to evaluate A to a true statement.
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<sstream>
using namespace std;

#define mod 1003
unordered_map<string,int>t;//here using a map for memoization rather than a matrix for better optimization
int expressionEval(string &A,int i,int j,bool eval){  //eval is to check if u want true or false outta the expression
    if(i>j){
        return 0;
    }
    if(i==j){
        if(eval==true){
            return A[i]=='T'; //either 1/0 returned which is fine since our functions returns an int
        }else{
            return A[i]=='F';
        }
    }
    stringstream ss;
    ss<<i<<" "<<j<<" "<<eval;
    string key=ss.str();  //making a unique key(i j)
    if(t.find(key)!=t.end())
        return t[key];
    int ans=0;
    for(int k=i+1;k<=j-1;k+=2){  //k increments by 2 to go from operand to operand and starts from i+1
       int lT=expressionEval(A,i,k-1,true)%mod;
       int lF=expressionEval(A,i,k-1,false)%mod; //not till k cause element at index k is the operand
       int rT=expressionEval(A,k+1,j,true)%mod;
       int rF=expressionEval(A,k+1,j,false)%mod;

       if(A[k]=='&'){
           if(eval==true){
               ans+=lT*rT;     //basic boolean algebra ladder to construct a truth table
           }else{
               ans+=lT*rF+rT*lF+rF*lF;
           }
       }
       else if(A[k]=='|'){
           if(eval==true){
               ans+=lT*rF+rT*lF+rT*lT;
           }else{
               ans+=lF*rF;
           }
       }
       else if(A[k]=='^'){
           if(eval==true){
               ans+=lT*rF+rT*lF;
           }else{
               ans+=lF*rF+rT*lT;
           }
       }

    }
    return t[key]=ans;  //store in mem map
}
int cnttrue(string A) {
    t.clear();
    return expressionEval(A,0,A.length()-1,true)%mod;
}

int main(){
    cout<<cnttrue("T^T^T^F|F&F^F|T^F^T");
}