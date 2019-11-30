#include<bits/stdc++.h>

using namespace std;

int findFirst(int ara[], int len, int x){
  int start = 0, end = len -1, mid;
  int result = -1;

  while(start <= end){
    mid = end + (start - end) / 2;
    if(ara[mid] == x) {
      result = mid;
      end  = mid - 1;
    }
    else if(x < ara[mid]) end = mid - 1;
    else start = mid + 1;
  }
  return result;
}

int findLast(int ara[], int len, int x){
  int start = 0, end = len -1, mid;
  int result = -1;

  while(start <= end){
    mid = end + (start - end) / 2;
    if(ara[mid] == x) {
      result = mid;
      start  = mid + 1;
    }
    else if(x < ara[mid]) end = mid - 1;
    else start = mid + 1;
  }
  return result;
}

int main() {
  // Sorted array
  int ara[] = {2, 4, 10, 10, 10, 18, 20};
  int len = sizeof(ara)/sizeof(ara[0]);

  std::cout << "Sorted array : ";
  for (int i = 0; i < len; i++) {
    std::cout << ara[i] << " ";
  }
  std::cout << '\n';

  int x = 10;
  int first = findFirst(ara, len, x);
  int last = findLast(ara, len, x);
  int total = last - first + 1;

  std::cout << "First occurence of " << x << ": " << first << '\n';
  std::cout << "Last occurence of " << x << ": " << last << '\n';
  std::cout << "Total occurences of " << x << ": " << total << '\n';


  return 0;
}
