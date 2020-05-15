
int Solution::gcd(int A, int B) {
    if (A == 0)
       return B;
    if (B == 0)
       return A;
    if (A == B)
        return A;
    if (A > B)
        return Solution::gcd(A-B, B);
    return Solution::gcd(A, B-A);
}

int Solution::gcd(int m, int n) {
         
        if(m < n)
               swap(m, n);
        
        if(n == 0)
               return m;
         

        return gcd(m % n, n);
  }