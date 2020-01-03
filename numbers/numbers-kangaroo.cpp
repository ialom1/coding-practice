#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  int x1, x2, v1, v2;

  std::cin >> x1 >> v1;
  std::cin >> x2 >> v2;

  while (x1 <= x2) {
    if(x1 == x2) {
      std::cout << "YES" << '\n';
      return 0;
    }
    x1 += v1; x2 += v2;
  }
  std::cout << "NO" << '\n';
  return 0;
}
