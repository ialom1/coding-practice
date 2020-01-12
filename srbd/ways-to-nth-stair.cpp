#include <iostream>

using namespace std;

// fibonacci equation
int fib(int n){
  if(n <= 1) return n;
  return fib(n-1) + fib(n-2);
}

int main() {
  int s = 5;
  std::cout << fib(s+1) << '\n';
}
