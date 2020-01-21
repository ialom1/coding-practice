#include <iostream>

using namespace std;

int _add(int a, int b){
  while(b != 0){
    int carry = a & b;
    a = a ^ b;
    b = carry << 1;
  }
  return a;
}
int _subtract(int a, int b){
  while(b != 0){
    int carry = ~a & b;
    a = a ^ b;
    b = carry << 1;
  }
  return a;
}

int findSum(int a, int b){
  if(a>=0 && b>=0){
    return _add(a, b);
  }
  else if(a<0 && b<0){
    return -_add(-a, -b);
  }
  else if(a<0 && b>=0){
    if(-a > b){
      return -_subtract(-a, b);
    }
    else{
      return _subtract(b, -a);
    }
  }
  else if(a>=0 && b<0){
    if(-b > a){
      return -_subtract(-b, a);
    }
    else {
      return _subtract(a, -b);
    }
  }
}

int main() {
  cout << findSum(1,2) << endl;
  cout << findSum(2,3) << endl;
  cout << findSum(-2,-3) << endl;
  cout << findSum(2,-3) << endl;
  cout << findSum(-2,3) << endl;

  return 0;
}
