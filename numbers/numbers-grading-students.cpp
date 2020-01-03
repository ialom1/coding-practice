#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  int n, arr[100];

  std::cin >> n;

  for (size_t i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  for (size_t i = 0; i < n; i++) {
    int r = arr[i] % 5;
    int q = arr[i] / 5;
    int diff = 0;
    if(r > 0) diff = (q+1)*5 - arr[i];
    // printf("%d %d %d ", r, q, diff);
    if(diff == 0 || arr[i] < 38) {
      std::cout << arr[i] << '\n';
      continue;
    }
    if (diff < 3) arr[i] = 5 * (q + 1);
    std::cout << arr[i] << '\n';

  }
  return 0;
}
