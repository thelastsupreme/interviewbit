// You are given A eggs, and you have access to a building with B floors from 1 to B.

// Each egg is identical in function, and if an egg breaks, you cannot drop it again.

// You know that there exists a floor C with 0 <= C <= B such that any egg dropped at a floor higher than C will break, and any egg dropped at or below floor C will not break.

// Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= B).

// Your goal is to know with certainty what the value of C is.

// What is the minimum number of moves that you need to know with certainty what C is, regardless of the initial value of C



// Problem Constraints
// 1 <= A <= 100
// 1 <= B <= 104


// Input Format
// First Argument is an integer A denoting number of eggs.

// Second Argument is an integer B denoting number of floors.



// Output Format
// Return an integer denoting the Minimum number of moves.



// Example Input
// Input 1:

//  A = 1
//  B = 2
// Input 2:

//  A = 2
//  B = 10


// Example Output
// Output 1:

//  2
// Output 2:

//  4 


// Example Explanation
// Explanation 1:

//  Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
//  Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
//  If it didn't break, then we know with certainty F = 2.

#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int>t;    //use map for optimization 
int eggDrop(int eggs,int floors){
    if(floors==0||floors==1){
        return floors;
    }
    if(eggs==1){
        return floors;
    }
    //used string stream instead of to_string to make a unique key
    stringstream ss;
    ss<<eggs<<" "<<floors;
    string key=ss.str();
    ss.clear();

    if(t.find(key)!=t.end()){
        return t[key];
    }
    int res=INT32_MAX;
    int bot,top=0;
    for(int k=1;k<=floors;k++){
        //***************code before optimization****************
        // int temp=1+max(eggDrop(eggs-1,k-1),eggDrop(eggs,floors-k)); //max cause assuming worst case here
        ss<<eggs-1<<" "<<k-1;
        string botkey=ss.str();
        if(t.find(botkey)!=t.end()){
            bot=t[botkey];
        }else{
            bot=eggDrop(eggs-1,k-1);
        }
        ss.clear();

        ss<<eggs<<" "<<floors-k;
        string topkey=ss.str();
        if(t.find(topkey)!=t.end()){
            top=t[topkey];
        }else{
            top=eggDrop(eggs,floors-k);
        }
        ss.clear();
        
        int temp=1+max(top,bot); 
        res=min(res,temp);
    }
    return t[key]=res;
}
int solve(int A, int B) {
    t.clear();
    return eggDrop(A,B);
}