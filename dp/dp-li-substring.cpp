#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void lis(int arr[], int n){
  int maxlen = 1, len = 1, maxlenIndex = 0;
  for (int i = 1; i < n; i++) {
    if(arr[i] > arr[i-1])
      len++;
    else{
      if(maxlen < len){
        maxlen = len;
        maxlenIndex = i - maxlen;
      }
      len = 1;
    }
  }
  // Compapre the last subarray
  if(maxlen < len){
    maxlen = len;
    maxlenIndex = n - maxlen;
  }

  std::cout << "Length of LI Substring: " << maxlen << '\n';
  for (int i = maxlenIndex; i < maxlen + maxlenIndex; i++) {
    std::cout << arr[i] << " ";
  }
}

int main() {
  int arr[] = { 5, 6, 3, 5, 7, 8, 9, 1, 2 };
  int n = sizeof(arr)/sizeof(arr[0]);
  lis(arr, n);
  return 0;
}
