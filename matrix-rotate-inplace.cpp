#include <stdio.h>
#include <iostream>

using namespace std;

#define M 4
#define N 4

void print(int arr[M][N]){
  for (int i = 0; i < M; i++){
    for (int j = 0; j < N; j++)
      std::cout << arr[i][j] << " ";
    std::cout << endl;
  }
}
void sawp(int &a, int &b) {
  int t = a;
  a = b; b = t;
}

void rotate90Clock(int arr[M][N]){
  for (int i = 0; i < M/2; i++) {
    for (int j = i; j < N-i-1; j++) {
      int temp = arr[i][j];
      arr[i][j] = arr[N-1-j][i];         // left to top
      arr[N-1-j][i] = arr[N-1-i][N-1-j]; // bottom to left
      arr[N-1-i][N-1-j] = arr[j][N-1-i]; // right to bottom
      arr[j][N-1-i] = temp;
    }
  }
}

void rotate90AntiClock(int arr[M][N]){
  for (int i = 0; i < M/2; i++) {
    for (int j = i; j < N-i-1; j++) {
      int temp = arr[i][j];
      arr[i][j] = arr[j][N-1-i];         // right to top
      arr[j][N-1-i] = arr[N-1-i][N-1-j]; // bottom to right
      arr[N-1-i][N-1-j] = arr[N-1-j][i]; // left to bottom
      arr[N-1-j][i] = temp;
    }
  }
}

int main() {
  int arr[M][N] = {
    { 1, 2, 3, 4 },
    { 5, 6, 7, 8 },
    { 9, 10, 11, 12 },
    { 13, 14, 15, 16 }
  };
  std::cout << "Initial Matrix------" << '\n';
  print(arr);

  rotate90Clock(arr);
  // rotate90AntiClock(arr);

  std::cout << "Rotated Matrix------" << '\n';
  print(arr);

  return 0;
}
