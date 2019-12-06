#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

long find(long x, long p[]) {
  if(p[x] == x) return x;
  return p[x] = find(p[x], p);
}

void unite(long a, long b, long p[]){
  p[find(b, p)] = find(a, p);
}

int main() {
  long n, e, a, b;
  std::cin >> n >> e;

  long p[n], set[n];
  for (long i = 0; i < n; i++) {
    p[i] = i; set[i] = 0;
  }

  for (long i = 0; i < e; i++) {
    std::cin >> a >> b;
    unite(a, b, p);
  }
  for(long i = 0; i < n; i++) {
    long p_i = find(i, p);
    ++set[p_i];
    // printf("%ld %ld %ld\n", i, p_i, set[p_i]);
  }
  long result = 0, psum = 0;
  for(auto i: set){
    result += psum*i;
    // printf("%ld %ld %ld \n", i, psum, result);
    psum += i;
  }
  std::cout << result << '\n';
  return 0;
}
