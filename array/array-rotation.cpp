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

void rotate(int arr[], int n){
  for (int i = 1; i < n; i++)
    swap(arr[i], arr[i-1]);
}

using namespace std;

int main() {
  int n, d;
  std::cin >> n >> d;
  int arr[n];

  for (int i = 0; i < n; i++)
    std::cin >> arr[i];

  for (int i = 0; i < n; i++){
    int p = i + d;
    if(p >= n) p%=(d+1);
    std::cout << arr[p] << " ";
  }
  std::cout << '\n';
}
