#include<bits/stdc++.h>

using namespace std;

int binarySearch(int ara[], int len, int x){
  int start = 0, end = len -1, mid;

  while(start <= end){
    mid = end + (start - end) / 2;
    if(ara[mid] == x) return mid;
    else if(x < ara[mid]) end = mid - 1;
    else start = mid + 1;
  }
  return - 1;
}

int main() {
  int ara[] = {9, 8, 1, 2, 5, 3, 7, 4, 6, 0};
  int len = sizeof(ara)/sizeof(ara[0]);
  sort(ara, ara + len);
  int x = 5;
  int pos = binarySearch(ara, len, x);
  std::cout << pos << '\n';
  std::cout << len << '\n';
  return 0;
}
