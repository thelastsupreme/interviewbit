#include <bits/stdc++.h>
using namespace std;

bool find(int A, unordered_map<int, vector<int>> &mp, vector<int> &vis, int B)
{
    if (B == A)
        return true;

    if (vis[B] == false)
    {
        vis[B] = true;
        for (int i = 0; i < mp[B].size(); i++)
        {
            bool found = find(A, mp, vis, mp[B][i]);
            if (found == true)
                return true;
        }
        // vis[B] = false; //no need to assign false cause if the node couldnt lead to dest
        //it wont ever lead to dest no matter how many times u come across it
        return false;
    }
    return false;
}

int solve(int A, vector<vector<int>> &B)
{
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < B.size(); i++)
    {
        mp[B[i][0]].push_back(B[i][1]);
    }
    vector<int>vis(A + 1, false);
    return find(A, mp, vis, 1);
}
int main()
{

}