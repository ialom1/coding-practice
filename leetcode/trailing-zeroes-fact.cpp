#include <iostream>

using namespace std;

// Number of zeroes trailing in  factorial of n
int trailingZeroes(int n){
  int count  = 0;
  for(int i=5; n/i>=1; i*=5){
    count += n/i;
  }
  return count;
}

int main() {
  std::cout << trailingZeroes(100) << '\n';
  return 0;
}
