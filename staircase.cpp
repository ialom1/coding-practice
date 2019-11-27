#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    if(i>0) std::cout << '\n';
    /* code */
    int hsh = i+1;
    int spc = n-hsh;

    while (spc --) {
      /* code */
      std::cout << " ";
    }
    while (hsh --) {
      /* code */
      std::cout << "#";
    }
  }

  return 0;
}
