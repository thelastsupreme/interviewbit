#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
using namespace std;

int main ()
{
  deque<int> mydeque (3,100);          // deque with 3 elements
  vector<int> myvector (2,200);        // vector with 2 elements

  stack<int> first;                    // empty stack
  stack<int> second (mydeque);         // stack initialized to copy of deque

  stack<int,vector<int> > third;  // empty stack using vector
  stack<int,vector<int> > fourth (myvector);

  cout << "size of first: " << first.size() << '\n';
  cout << "size of second: " << second.size() << '\n';
  cout << "size of third: " << third.size() << '\n';
  cout << "size of fourth: " << fourth.size() << '\n';

  return 0;
}
