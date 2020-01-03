#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int main() {

  int n, i, j;
  cin >> n;

  int ara[n][n], d1 = 0, d2 = 0, temp;

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      // std::cout << i << " " << j << '\n';
      cin >> temp;
      if(i == j) d1 += temp;
      if(i == (n-j-1)) d2 += temp;
      std::cout << d1 << " " << d2 << '\n';
    }
  }

  cout << abs(d1 - d2) << endl;
  return 0;
}
