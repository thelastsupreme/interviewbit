vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<string,vector<int>> m;
    string s;
    for(int i=0;i<A.size();i++)
    {
        s=A[i];
        sort(s.begin(),s.end());
        m[s].push_back(i+1);
    }
    vector<vector<int>> result;
    auto it=m.begin();
    while(it!=m.end())
    {
        result.push_back(it->second);
        it++;
    }
    return result;
}

