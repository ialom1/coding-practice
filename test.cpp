#include <iostream>

using namespace std;
int add(int a, int b){
  while(b != 0){
    int carry = a & b;
    a = a ^ b;
    b = carry << 1;
  }
  return a;
}

int getSum(int a, int b) {
  if(a>=0 && b>=0) {
    std::cout << "+a+b" << '\n';
    return add(a,b);
  }

  if(a<0 && b<0) {
    std::cout << "-a-b" << '\n';
    return -add(-a,-b);
  }

  if(a<0 && b>=0){
    std::cout << "-a+b" << '\n';
    if(-a > b) return -add(-a, b);
    else return add(-a, b);
  }
  if(a>=0 && b<0){
    std::cout << "+a-b" << '\n';
    if(-b > a) return -add(a, -b);
    else return add(a, -b);
  }
}

int main() {
  std::cout << getSum(2, -3) << '\n';
  return 0;
}
