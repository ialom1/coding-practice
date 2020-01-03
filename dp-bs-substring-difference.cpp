#include <iostream>

using namespace std;

int c[1505][1505] = {0};
int l, k;

bool solve(int mid) {
  for(int i=mid; i<=l; i++){
    for(int j=mid; j<=l; j++){
      int temp = c[i][j] - c[i-mid][j-mid];
      if(temp <= k) return true;
    }
  }
  return false;
}

int main(){
  int cases;
  std::cin >> cases;
  while (cases--) {
    std::cin >> k;
    string a, b;
    std::cin >> a >> b;
    l = a.length();
    // std::cout << a << b << l << '\n';

    for(int i=0; i<l; i++){
      for(int j=0; j<l; j++){
        if(a[i] == b[j])
          c[i+1][j+1] = c[i][j];
        else
          c[i+1][j+1] = c[i][j] + 1;
      }
    }

    int low = 0, high = l, mid;
    while (low < high) {
      // std::cout << low << high << '\n';
      // mid = low + (high-low)/2;
      mid = (low + high + 1) >> 1;
      if(solve(mid)) low = mid;
      else high = mid - 1;
    }
    std::cout << low << '\n';
  }
  return 0;
}
