#include <stdio.h>
#include <iostream>

using namespace std;

int countConsecutive(int n){
  int count = 0;
  for (int i = 1; i*(i+1) <= 2*n; i++) {
    int sum = i*(i+1)/2;
    double a = (1.0*n-sum)/2;
    std::cout << i << " " << sum << " " << a << '\n';
    if(a-(int)a == 0.0) ++count;
  }
  return count;
}

int main(){
  std::cout << countConsecutive(15) << '\n';

  return 0;
}
