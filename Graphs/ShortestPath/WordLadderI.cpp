// Given two words A and B, and a dictionary, C, find the length of shortest transformation sequence from A to B, such that:

// You must change exactly one character in every transformation.
// Each intermediate word must exist in the dictionary.
// Note:

// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.


// Input Format:

// The first argument of input contains a string, A.
// The second argument of input contains a string, B.
// The third argument of input contains an array of strings, C.
// Output Format:

// Return an integer representing the minimum number of steps required to change string A to string B.
// Constraints:

// 1 <= length(A), length(B), length(C[i]) <= 25
// 1 <= length(C) <= 5e3
// Example :

// Input 1:
//     A = "hit"
//     B = "cog"
//     C = ["hot", "dot", "dog", "lot", "log"]

// Output 1:
//     5

// Explanation 1:
//     "hit" -> "hot" -> "dot" -> "dog" -> "cog"
#include <bits/stdc++.h>
using namespace std;

void map_print(unordered_map<string,int>mp)
{
    auto it=mp.begin();
    while(it!=mp.end())
    {
        cout<<it->first<<" --> "<<it->second<<endl;
        it++;
    }
    cout<<endl;
}
int solve(string start, string end, vector<string> &dict){
    
    unordered_map<string, bool>vis; //to mark visited
    unordered_map<string, int>dist; //to maintain distance

    for(int i = 0; i < (int)dict.size(); i++){
        vis[dict[i]] = false;             //set all as not visited
    }
    vis[end]=false;
    queue<string>q;
    q.push(start);
    vis[start] = true;        //insert into map as true
    
    while(!q.empty()){
        
        string node = q.front();
        q.pop();
        for(int i = 0; i < node.size(); i++){
            string temp = node;
            for(int ch = 'a'; ch <= 'z'; ch++){  
                temp[i] = ch;   //replacing a char in the word with 26 aphabets
                if(vis.find(temp) != vis.end() && !vis[temp]){ //if the word exists and is not visted
                    q.push(temp);
                    // cout<<temp<<endl;
                    vis[temp] = true;          //set it to tue
                    dist[temp] = dist[node]+1; //and set the distance
                }
            }
        }
    }
    map_print(dist);
    return dist[end]+1;  //return the distance of resulting word
}

int main()
{
    vector<string>C={"hot","dot","dog","lot","log"};
    cout<<solve("hit","cog",C);
}