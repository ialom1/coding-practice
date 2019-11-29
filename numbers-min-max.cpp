#include <stdio.h>
#include <iostream>
#include <limits.h>
#include "algorithm"

using namespace std;

int main() {
  long long ara[5], sum = 0;

  for (int i = 0; i < 5; i++) {
    /* code */
    cin >> ara[i];
    sum += ara[i];
  }

  sort(ara, ara+5);

  std::cout << sum-ara[4] << " " << sum-ara[0] << '\n';
  return 0;
}
