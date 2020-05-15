#include<iostream>
using namespace std;

int main()
{
    int a[5]={1,2,3,4,5};
    int * p;
    p=&a[0];

    cout<<"1st :"<< *p++ <<endl;  // same as *(p++): increment pointer, and dereference unincremented address
    cout<<"2nd :"<<*++p <<endl ; // same as *(++p): increment pointer, and dereference incremented address
    cout<<"3rd :"<< ++*p <<endl  ;// same as ++(*p): dereference pointer, and increment the value it points to
    cout<<"4th :"<< (*p)++ <<endl;// dereference pointer, and post-increment the value it points to
   /* int a[]={1,2,3,4,5};
    int b[]={0,0,0,0,0};
    int *p=a;
    int *q=b;
    for(int i=0;i<5;i++)
        *p++=*q++;
    for(int i=0; i<5;i++)
        cout<<"A of "<<i+1<<": "<<a[i]<<endl;
*/
}
/* *p++=*q++;
    implies
    *p=*q
    then p++ and q++
    */

