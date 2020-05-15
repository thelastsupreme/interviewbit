//krutikas code
int Solution::singleNumber(const vector<int> &A) {
     if(A.size()==0) return 0;
    if(A.size()==1) return A[0];
    vector<int> B(A);
    sort(B.begin(),B.end());
   // print(B);
    //cout<<endl;
    for(int i=0;i<B.size();i++)
    {
        if(i==B.size()-1) return B[i];
        if(B[i]==B[i+1]) i+=2;
        else return B[i];
    }

}
//approach that could have been thought of
 int singleNumber(const vector<int> &A) {
        int n = A.size();
        int count[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                if ((A[j] >> i) & 1) {
                    count[i]++;
                }
            }
            result |= ((count[i] % 3) << i);
        }
        return result;
    }
}
//big brain codes

int Solution::singleNumber(const vector<int> &A)
{
    int a = 0, b = 0;
    for(int i = 0; i < A.size(); i++){
        a = (a ^ A[i]) & ~b;
        b = (b ^ A[i]) & ~a;
    }
    return a;
}

int singleNumber(const vector<int> &A) {
    int n = A.size();
    int ones = 0, twos = 0, threes = 0;
    for (int i = 0; i < n; i++) {
        twos |= ones & A[i];
        ones ^= A[i];
        threes = ones & twos;
        ones &= ~threes;
        twos &= ~threes;
    }
    return ones;
}
