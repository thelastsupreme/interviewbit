#include<iostream>
using namespace std;

// & extracts address
// * extracts value from address
int main()
{
   /*
    int myvar=25;
    int *foo;
    foo=&myvar;
    cout<<&myvar<<endl;
    cout<<*foo<<endl;
    cout<<foo<<endl;
   */
  int firstvalue, secondvalue;
  int * mypointer;

  mypointer = &firstvalue;
  *mypointer = 10;
  mypointer = &secondvalue;
  *mypointer = 20;
  cout << "firstvalue is " << firstvalue << '\n';
  cout << "secondvalue is " << secondvalue << '\n';
  return 0;

}
