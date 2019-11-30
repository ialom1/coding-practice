#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  double p=0, n=0, z=0, total = cases;

  while (cases --) {
    /* code */
    int temp;
    std::cin >> temp;

    if(temp == 0) ++z;
    else if(temp > 0) ++p;
    else ++n;
  }

  std::cout << p/total << '\n';
  std::cout << n/total << '\n';
  std::cout << z/total << '\n';

  return 0;
}
