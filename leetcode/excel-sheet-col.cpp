#include <iostream>

using namespace std;

int main() {
  string str;
  std::cin >> str;
  std::cout << str << '\n';
  int n = 0;
  for(char c: str){
    n = (n * 26) + (c - 'A' + 1);
    std::cout << n << '\n';
  }
  std::cout << n << '\n';
  return 0;
}
