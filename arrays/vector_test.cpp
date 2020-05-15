/*#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
int main()
{
  vector<int>A={1, 2, 5, -7, 2, 5};
    A.assign(A.size(),5);
    print(A);
  }
  */
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;
int main ()
{
  std::string str_dec = "2001, A Space Odyssey";
  std::string str_hex = "40c3";
  std::string str_bin = "-10010110001";
  std::string str_auto = "0x7f";
    string a="12";
    string b="15";
  std::string::size_type sz;   // alias of size_t

  int i_dec = std::stoi (a,&sz);
   int i_dec1 = std::stoi (b,&sz);
  int i_hex = std::stoi (str_hex,nullptr,16);
  int i_bin = std::stoi (str_bin,nullptr,2);
  int i_auto = std::stoi (str_auto,nullptr,0);

  std::cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n";
  std::cout << str_hex << ": " << i_hex << '\n';
  std::cout << str_bin << ": " << i_bin << '\n';
  std::cout << str_auto << ": " << i_auto << '\n';
    cout<<i_dec+i_dec1;
  return 0;
}
