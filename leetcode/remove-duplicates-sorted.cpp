#include <iostream>

using namespace std;

int removeDuplicates(int ara[], int len){
  if(len == 0 || len == 1) return len;

  int temp[len], k = 0;
  for(int i=0; i<len-1; i++){
    if(ara[i] != ara[i+1]){
      temp[k++] = ara[i];
    }
  }
  temp[k++] = ara[len-1];
  for(int i=0; i<k; i++)
    ara[i] = temp[i];
  return k;
}

int main() {
  int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  // removeDuplicates() returns new size of
  // array.
  n = removeDuplicates(arr, n);

  // Print updated array
  for (int i=0; i<n; i++)
     cout << arr[i] << " ";

  return 0;
}
