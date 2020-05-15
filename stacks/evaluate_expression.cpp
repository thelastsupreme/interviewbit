int Solution::evalRPN(vector<string> &A) {
    int res=0;
    stack<int>s;
    int t1;
    int t2;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        if(A[i]=="+"||A[i]=="-"||A[i]=="/"||A[i]=="*")
        {
            if(!s.empty())
            {
                t2=s.top();
                s.pop();
            }
            if(!s.empty())
            {
                t1=s.top();
                s.pop();
            }
            if(A[i]=="+")
                s.push(t1+t2);
            else if(A[i]=="-")
                s.push(t1-t2);
            else if(A[i]=="/")
                s.push(t1/t2);
            else if(A[i]=="*")
                s.push(t1*t2);

        }
        else
            s.push(stoi(A[i]));
    }
        return s.top();

}
