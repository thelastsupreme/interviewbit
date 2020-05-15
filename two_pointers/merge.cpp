
//our code
void Solution::merge(vector<int> &A, vector<int> &B) {
    A.insert(A.end(), B.begin(), B.end());
    sort(A.begin(),A.end());
}

//interview bit
void Solution::merge(vector<int> &A, vector<int> &B)
{
    int i = A.size() - 1; // i pointing to last index of A
    int j = B.size() - 1; // j pointing to last index of B

    int lastPos = A.size() + B.size() - 1; // lastPos pointing to last index of merged array A and B

    A.resize(A.size() + B.size());

    while(j >= 0)
    {
        if(i >= 0 and A[i] > B[j])
            A[lastPos--] = A[i--];
        else
            A[lastPos--] = B[j--];
    }

}
