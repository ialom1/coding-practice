#include <iostream>

using namespace std;

void arrange(int arr[], int n){
  int even = 0, odd = 1;
  while (true) {
    while(even < n && arr[even]%2 == 0)
      even += 2;
    while(odd < n && arr[odd]%2 == 1)
      odd += 2;
    if(even < n && odd < n){
      int t = arr[even];
      arr[even] = arr[odd];
      arr[odd] = t;
    } else {
      break;
    }
  }
}

void print(int arr[], int n){
  for(int i=0; i<n; i++)
    std::cout << arr[i] << ' ';
  std::cout << '\n';
}

int main() {
  int arr[] = { 3, 6, 12, 1, 5, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    print(arr, n);

    arrange(arr, n);

    cout << "\nModified Array: ";
    print(arr, n);

    return 0;
}
