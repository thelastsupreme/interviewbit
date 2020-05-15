int Solution::colorful(int A) {
    unordered_map<long long int,int> m;
    vector<int>v;
    while(A>0)
    {
        v.push_back(A%10);
        A=A/10;
    }
    reverse(v.begin(),v.end());
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        int num=1;
        for(int j=i;j<n;j++)
        {
            num=num*v[j];
            if(m.find(num)!=m.end())
                return 0;
            else
                m.insert({num,j});
        }
    }
    return 1;
}
