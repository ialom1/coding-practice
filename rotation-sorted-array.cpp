#include<bits/stdc++.h>

using namespace std;

int findMin(int ara[], int len, int x){
  int start = 0, end = len -1, mid;

  while(start <= end){
    mid = end + (start - end) / 2;

    if(ara[start] <= ara[end])
      return start;

    else if((ara[mid] <= ara[start]) && (ara[mid] <= ara[end]))
      return mid;

    else if(ara[mid] <= ara[start])
      end = mid - 1;
    else
      start = mid + 1;
  }
  return -1;
}

int main() {
  // Sorted array
  int ara[] = {11, 12, 15, 18, 2, 5, 6, 8};
  int len = sizeof(ara)/sizeof(ara[0]);

  std::cout << "Rotated array : ";
  for (int i = 0; i < len; i++) {
    std::cout << ara[i] << " ";
  }
  std::cout << '\n';

  int x = 10;
  int minIndex = findMin (ara, len, x);

  std::cout << "Number of rotations: " << minIndex << '\n';

  return 0;
}
