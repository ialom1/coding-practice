#include <stdio.h>
#include <iostream>

void swap(int &a, int &b) {
  int t = a;
  a = b; b = t;
}
void print(int arr[], int n) {
  for (size_t i = 0; i < n; i++)
    std::cout << arr[i] << " ";
  std::cout << '\n';
}

void rotate(int arr[], int n){ // clockwise
  for (int i = 1; i < n; i++)
    swap(arr[i], arr[i-1]);
}
void rotateAnti(int arr[], int n){ // clockwise
  for (int i = n-1; i > 0; i--)
    swap(arr[i], arr[i-1]);
}

using namespace std;

int main() {
  int n, d;
  std::cin >> n >> d;
  int arr[n];

  for (int i = 0; i < n; i++)
    std::cin >> arr[i];

  for (int i = 0; i < d; i++){
    std::cout << "Rotation " << i << '\n';
    rotate(arr, n);
    print(arr, n);
  }
  std::cout << '\n';
}
