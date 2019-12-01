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

void transpose(int arr[M][N]){
  for (int i = 0; i < M; i++) {
    for (int j = i; j < N; j++) {
      swap(arr[i][j], arr[j][i]);
    }
  }
}

void reverseCols(int arr[M][N]){
  for (int i = 0; i < N; i++) {
    for (int j = 0, k = (N - 1); j < k; j++, k--) {
      swap(arr[j][i], arr[k][i]);
    }
  }
}

void rotate90(int arr[M][N]){
  transpose(arr);
  reverseCols(arr);
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

  rotate90(arr);

  std::cout << "Rotated Matrix------" << '\n';
  print(arr);

  return 0;
}
