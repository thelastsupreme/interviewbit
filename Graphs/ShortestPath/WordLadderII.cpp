// Given two words (start and end), and a dictionary, find the shortest transformation sequence from start to end, such that:

// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// If there are multiple such sequence of shortest length, return all of them. Refer to the example for more details.

// Note:

// All words have the same length.
// All words contain only lowercase alphabetic characters.
// Input Format

// The first argument is string start.
// The second argument is string end.
// The third argument is an array of strings dict
// Output Format

// Return all transformation sequences such that first word of each sequence is start and last word is end, all intermediate words belongs to dictionary(dict) and consecutive words had atmost 1 difference.  
// Example :

// :

// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// Return

//   [
//     ["hit","hot","dot","dog","cog"],
//     ["hit","hot","lot","log","cog"]
//   ]
  
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

vector<vector<string>>findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_map<string, int> um;
    vector<vector<string>> res;
    for (const auto w : wordList) //for all words put them in map with INT_MAX
        um.insert({w, INT_MAX});
    um[beginWord] = 0;           //first word with 0
    queue<pair<string, vector<string>>> q;  //a pair of string and vector of strings -> word and its path
    q.push({beginWord, {beginWord}});       
    while (!q.empty())
    {
        auto n = q.front();
        q.pop();
        string w = n.first;
        auto v = n.second;
        if (w == endWord) //if the endword is found
        {
            res.push_back(v); //push the whole path into result
            continue;
        }
        for (int i = 0; i < w.size(); i++)
        {
            string t = w;   
            for (char c = 'a'; c <= 'z'; c++)
            {
                t[i] = c;
                if (t == w)
                    continue;
                if (um.find(t) == um.end())
                    continue;
                if (um[t] < (int)v.size()) //if the word was found before in less steps then leave
                    continue;   
                um[t] = (int)v.size(); //put the path size to get to that word
                v.push_back(t); //add word to path
                q.push({t, v}); //push the new word along its path
                v.pop_back();  //remove that word for the next loop
            }
        }
    }
    return res;
}
