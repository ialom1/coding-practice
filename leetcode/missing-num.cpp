#include <iostream>

using namespace std;

int getMissingNo(int ara[], int len){
  int sum = (len+1)*(len+2)/2;
  for(int i=0; i<len; i++){
    sum -= ara[i];
  }
  return sum;
}

int main() {
  int arr[] = { 1, 2, 4, 5, 6 };
  int n = sizeof(arr) / sizeof(arr[0]);
  int miss = getMissingNo(arr, n);
  cout << miss;
  return 0;
}
