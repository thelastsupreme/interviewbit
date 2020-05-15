#include <iostream>       // std::cin, std::cout
#include <stack>          // std::stack
#include <string>         // std::string, std::getline(string)
using namespace std;
int main ()
{
  stack<string> mystack;

  mystack.emplace ("First sentence");
  mystack.emplace ("Second sentence");

  cout << "my stack contains:\n";
  while (!mystack.empty())
  {
    cout << mystack.top() << '\n';
    mystack.pop();
  }

  return 0;
}
