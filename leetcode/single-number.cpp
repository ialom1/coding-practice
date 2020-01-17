#include <iostream>

using namespace std;

int _find(int arr[], int len){
  int t[len] = {0};
  for(int i=0; i<len; i++){
    int v = arr[i];
    ++t[v];
  }
  for(int i=0; i<len; i++){
    if(t[i] == 1) return i;
  }
  return -1;
}

int main() {
  int arr[] = {4,1,2,1,2};
  int len = sizeof(arr)/sizeof(arr[0]);
  int ans = _find(arr, len);
  std::cout << ans << '\n';
  return 0;
}
