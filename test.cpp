#include <iostream>

using namespace std;

void copyArray(int a[], int b[], int n){
  for(int i=0; i<n; i++)
    a[i] = b[i];
  a[n] = '\0';
}

int main() {
  int a[] = {1,2,3,4,5};
  int b[] = {6,7,8,9};
  int m = sizeof(a)/sizeof(a[0]);
  int n = sizeof(b)/sizeof(b[0]);

  copyArray(a, b, n);

  for(int i=0; i<sizeof(a)/sizeof(a[0]); i++)
  std::cout << a[i] << ' ';
  std::cout << '\n';
  for(int i=0; i<sizeof(b)/sizeof(b[0]); i++)
  std::cout << b[i] << ' ';
  std::cout << '\n';

  return 0;
}
