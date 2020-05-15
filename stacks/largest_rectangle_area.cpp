//prabhaths code
int Solution::largestRectangleArea(vector<int> &A) {
    if(A.size()==1)
        return A[0];
    stack<int>s;
    int res=0;
   // int minn=0;
    A.push_back(0);
    for(int i=0;i<A.size();i++)
    {
        //minn=min(minn,A[i]);
        if(s.empty()||A[i]>=A[s.top()])
        {
            s.push(i);
        }
        else
        {
            int maxx_idx=s.top();
            s.pop();
            int k;
            if(s.empty())
                k=i;
            else
                k=i-s.top()-1;
            res=max(res,A[maxx_idx]*k);
            i--;
        }
    }
    return res;
}
//krutikas code
int Solution::largestRectangleArea(vector<int> &A) {
    int minn;
    int height=0;
    int width=0;
    int area=0;
    if(A.size()==1)
      return A[0];
    for(int i=0;i<A.size();i++)
    {
        minn=A[i];
        for(int j=i;j<A.size();j++)
        {
            height=min(minn,A[j]);
            if(height<minn)
               minn=height;
            width=j-i+1;   //j-i
            if(height*width>=area)
              area=height*width;
        }
    }
    return area;

}

