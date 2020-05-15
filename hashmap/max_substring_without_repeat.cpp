//prakritis code
int Solution::lengthOfLongestSubstring(string A)
{
    if(A.empty())
        return 0;
    unordered_map<char,int> m;
    int c=0,res=0;
    auto i=0;
    while(i<A.size())
    {
        if(m.find(A[i])==m.end())
        {
            m[A[i]]=i;
            ++c;
            ++i;
        }
        else
        {
            i=m[A[i]]+1;
            m.clear();
            res= max(c,res);
            c=0;
        }
    }
    res = max(c,res);
    return res;
}

//prabhaths code
int Solution::lengthOfLongestSubstring(string A) {
    set<char>s;
    int l=1;
    int idx=0;
    for(int i=0;i<A.length();i++)
    {
        if(s.find(A[i])==s.end())
        {
            s.insert(A[i]);
        }
        else
        {
            while(A[idx]!=A[i])
            {
                s.erase(A[idx]);
                idx++;
            }
            idx++;
        }
        l=max(l,i-idx+1);
    }
    return l;
}

//krutikas code
int Solution::lengthOfLongestSubstring(string A) {
    //unordered_map<int,int> m;
    string s;
    if(A.size()==1)
       return 1;
    for(int n=A.size();n>0;n--)
    {
        for(int i=0;i<A.size();i++)
        {
            s=A.substr(i,n-i); //???
            set<char>st(s.begin(),s.end());  //note
            if(s.size()==st.size())
               return s.size();
        }
    }
    //return 1;
}

