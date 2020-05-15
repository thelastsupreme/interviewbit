//prabhaths code
int Solution::removeElement(vector<int> &A, int B) {
    int n=A.size();
    int countt=count(A.begin(),A.end(),B);
    int first_idx=-1;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==B)
        {
            first_idx=i;
            break;
        }
    }
    int next=first_idx+1;
    while(next<A.size()&&first_idx>=0)
    {
        if(A[next]!=B)
            {
                A[first_idx]=A[next];
                first_idx++;
            }
        next++;
    }
    A.resize(n-countt);
    return A.size();
}
//best code
int removeElement(int A[], int n, int elem) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == elem) continue;
        else {
            A[count] = A[i];
            count++;
        }
    }
    return count;
}
//bestest code
int Solution::removeElement(vector &A, int B)
{
    A.erase(remove(A.begin(),A.end(),B),A.end());
    return A.size();
}

int Solution::removeElement(vector<int> &A, int B)
{
  int countt=count(A.begin(),A.end(),B);
  remove(A.begin(),A.end(),B);
  A.resize(A.size()-countt);
  return A.size();
}
