//prabhaths code
unsigned int Solution::reverse(unsigned int A) {
    unsigned int res=0;
    int i=0;
    while(A)
    {
        res=res+(A%2)*pow(2,32-i-1);
        A/=2;
        i++;
    }
    return res;
}
//krutikas code
unsigned int Solution::reverse(unsigned int A) {
    int temp;
    bitset<32>binary(A);
    for(int i=0;i<32/2;i++)
           swap(binary[i],binary[32-i-1]);
    return binary.to_ulong();
}
