#include <iostream>

using namespace std;

int swapNibbles(int x){
  int ln = x & 0x0F;
  int hn = x & 0xF0;
  return ln << 4 | hn >> 4;
}

int main() {
  int x = 100;
  std::cout << swapNibbles(x) << '\n';
  return 0;
}
