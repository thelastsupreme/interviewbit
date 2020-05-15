
int Solution::maxSubArray(const vector<int> &A) {
    int best = INT_MIN, sum = 0;
    if(A.size()==1)
        return A[0];
        for (int i = 0; i < A.size(); i++)
        {
            sum = max(A[i], sum + A[i]);
            best = max(best, sum);
        }
    return best;
}

//recursive by approach by krutika madam jiiii yet to be coded...check for min element and remove it split into two arrays
