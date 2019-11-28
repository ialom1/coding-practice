#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void printList(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++){
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

void lis(int arr[], int n){
  std::vector<int> list[n];

  list[0].push_back(arr[0]);
  // printList(list[0]);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if(arr[i] > arr[j]
          && list[i].size() < list[j].size() + 1)
        list[i] = list[j];
    }
    list[i].push_back(arr[i]);
    // printList(list[i]);
  }
  std::vector<int> max = list[0];
  for (int i=0; i<n; i++) {
    if(list[i].size() > max.size())
      max = list[i];
  }
  printList(max);
}

int main() {
  int arr[] = { 3, 2, 6, 4, 5, 1 };
  int n = sizeof(arr)/sizeof(arr[0]);
  lis(arr, n);
  return 0;
}
