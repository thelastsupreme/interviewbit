#include<iostream>
using namespace std;

void bin(unsigned n)
{
    /* step 1 */
    if (n > 1)
        bin(n/2);

    /* step 2 */
    cout << n % 2;
}
int main()
{
   int n=4;
   int x=17;
   bin(x);
   cout<<endl;
   bin(x&(x-1)); //clears least significant bit
   cout<<endl;
   bin(x & ~(x-1));//extract lsb
   cout<<endl;
   bin(x & (x + (1 << n)));
   cout<<endl;
   bin(x | (x + 1)); //x with lowest cleared bit set
   cout<<endl;
   bin(x | ~(x + 1)); //extracts lowest clear bit set and all other bits are set
   cout<<endl;
   bin(x | (x - (1 << 2)));
   cout<<endl;
   bin(x | ~(x - (1 << 2))); //set n bits ...then set rest of the bits after length as 1
   cout<<endl;
}
