#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  int s, t, a, b, m, n, apples = 0, oranges = 0;
  std::cin >> s >> t >> a >> b >> m >>n;

  for (size_t i = 0; i < m; i++) {
    int temp, dist;
    std::cin >> temp;
    dist = temp + a;
    if(dist >= s && dist <= t) ++apples;
  }
  for (size_t i = 0; i < n; i++) {
    int temp, dist;
    std::cin >> temp;
    dist = temp + b;
    if(dist >= s && dist <= t) ++oranges;
  }

  std::cout << apples << '\n' << oranges << '\n';
  return 0;
}
