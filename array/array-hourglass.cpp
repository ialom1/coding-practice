#include <stdio.h>
#include <iostream>

using namespace std;

#define R 6
#define C 6

int main() {
  int arr[R][C];
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      std::cin >> arr[i][j];
    }
  }
  int max = -9999;
  for (int i = 1; i < R - 1; i++) {
    for (int j = 1; j < C - 1; j++) {
      int sum = arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1] +
                arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1] +
                arr[i][j];
      if(max < sum) max = sum;
    }
  }
  std::cout << max << '\n';
  return 0;
}
