// There are a total of A courses you have to take, labeled from 1 to A.

// Some courses may have prerequisites, for example to take course 2 you have to first take course 1, which is expressed as a pair: [1,2].

// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

// Return 1 if it is possible to finish all the courses, or 0 if it is not possible to finish all the courses.

// Input Format:

// The first argument of input contains an integer A, representing the number of courses.
// The second argument of input contains an integer array, B.
// The third argument of input contains an integer array, C.
// Output Format:

// Return a boolean value:
//     1 : If it is possible to complete all the courses.
//     0 : If it is not possible to complete all the courses.
// Constraints:

// 1 <= A <= 6e4
// 1 <= length(B) = length(C) <= 1e5
// 1 <= B[i], C[i] <= A
// Example:

// Input 1:
//     A = 3
//     B = [1, 2]
//     C = [2, 3]

// Output 1:
//     1

// Explanation 1:
//     It is possible to complete the courses in the following order:
//         1 -> 2 -> 3

// Input 2:
//     A = 2
//     B = [1, 2]
//     C = [2, 1]

// Output 2:
//     0

// Explanation 2:
//     It is not possible to complete all the courses.
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &input)
{
	for (int i = 0; i < input.size(); i++) {
		cout << input.at(i) << ' ';
	}
    cout<<endl;
}

void print_matrix(vector<vector<int>>&matrix)
{
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();i++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void print_map(unordered_map<int,vector<int>>&map)
{
    auto it=map.begin();
    while(it!=map.end())
    {
        cout<<it->first<<" --> ";
        print(it->second);
        it++;
    }
}

void DFS_util(int s,vector<bool>&visited,vector<int>&ans,unordered_map<int,vector<int>>adj)
{
    // cout<<"vertex : "<<s<<endl;
    visited[s]=true;
    for(int i=0;i<adj[s].size();i++)
    {
        if(!visited[adj[s][i]])
            DFS_util(adj[s][i],visited,ans,adj);
    }
    ans.push_back(s);  //important step to push the source after u traversed the whole path
}

vector<int> topologicalSort(int A,unordered_map<int,vector<int>>&adj)
{
    vector<bool>visited(A+1,false);
    vector<int>ans;
    for(int i=1;i<A+1;i++)
    {
        if(!visited[i])
            DFS_util(i,visited,ans,adj);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int solve(int A,vector<int>&B,vector<int>&C)
{
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<B.size();i++)
    {
        adj[B[i]].push_back(C[i]);
    }
    vector<int>result=topologicalSort(A,adj);
    // print(result);
    for(int i=0;i<B.size();i++)
    {
        int Bidx=find(result.begin(),result.end(),B[i])-result.begin();
        int Cidx=find(result.begin(),result.end(),C[i])-result.begin();
        if(Cidx<Bidx)
            return 0;
    }
    return 1;
}
/////////////////EDITORIAL//////////////////////
// bool dfs(vector<vector<int>>& graph, vector<int>& vis, int u){
//     vis[u] = 1;
//     bool ans = false;
//     for(auto v : graph[u]){
//         if(vis[v]==1){
//             ans = true;
//             continue;
//         }
//         else if(vis[v]==2){
//             continue;
//         }
//         ans = ans | dfs(graph, vis, v);
        
//     }
//     vis[u] = 2;
//     return ans;
// }

// int solve_editorial(int a, vector<int> &b, vector<int> &c) {
//     int n = b.size();
//     vector<vector<int>> graph(a+1);
//     for(int i = 0; i<n; i++){
//         int x = b[i], y = c[i];
//         graph[x].push_back(y);
//     }
//     vector<int> vis(a+1, 0);
    
//     for(int i = 1; i<=n; i++){
//         if(vis[i]==0){
//             bool ans = dfs(graph, vis, i);
//             if(ans) return 0;
//         }
//     }
//     return 1;
// }
int main()
{
    int A=8;
    vector<int>B={1,2,3,4,5,8};
    vector<int>C={2,3,4,5,6,7};
    cout<<solve(A,B,C);
}