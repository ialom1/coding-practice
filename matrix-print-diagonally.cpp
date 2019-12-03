#include <stdio.h>
#include <iostream>

using namespace std;

#define M 4
#define N 4
#define endRow N-j-1 // w.r.t to i
#define endCol N-i-1 // w.r.t to j

void print(int arr[M][N]){
  for (int i = 0; i < M; i++){
    for (int j = 0; j < N; j++)
      std::cout << arr[i][j] << " ";
    std::cout << endl;
  }
}

void printDiagonally(int arr[M][N]){
  for (int i = 0; i < M; i++) {
    int row = i, col = 0;
    while (row >= 0) {
      std::cout << arr[row][col] << ' ';
      --row; ++col;
    }
    std::cout << '\n';
  }
  for (int j = 1; j < N; j++) {
    int row = N-1, col = j;
    while(col < N){
      std::cout << arr[row][col] << ' ';
      --row; ++col;
    }
    std::cout << '\n';
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

  std::cout << "Diagonally Traversing------" << '\n';
  printDiagonally(arr);

  return 0;
}
