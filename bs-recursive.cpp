#include<bits/stdc++.h>

using namespace std;

int binarySearch(int ara[], int start, int end, int x){
  if(start > end) return -1;
  int mid = (end + (start - end) / 2);

  if(ara[mid] == x) return mid;
  else if(x < ara[mid]) return binarySearch(ara, start, mid - 1, x);
  else return binarySearch(ara, mid + 1, end, x);
}

int main() {
  int ara[] = {9, 8, 1, 2, 5, 3, 7, 4, 6, 0};
  int len = sizeof(ara)/sizeof(ara[0]);
  sort(ara, ara + len);

  std::cout << "Sorted array : ";
  for (int i = 0; i < len; i++) {
    std::cout << ara[i] << " ";
  }
  std::cout << '\n';

  int x = 11;
  int start = 0, end = len - 1;
  int pos = binarySearch(ara, start, end, x);

  std::cout << "Position of " << x << ": " << pos << '\n';

  return 0;
}
