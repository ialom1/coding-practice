#include <iostream>

using namespace std;

int main() {
  int arr[] = {1,-1,2,3,4,5,-1,-1,6,7,-1,8,-1,9,10,-1,-1,11,-1,12,-1,13,-1,-1,14};
  int n = sizeof(arr)/sizeof(arr[0]);


  // n-ary tree to adjacency list
  for(int i=0, j=1; i<n && j<n; i++){
    int head = arr[i];
    if(head == -1) continue;
    std::cout << head << " -> ";
    while(arr[++j] != -1 && j<n){
      std::cout << arr[j] << " ";
    }
    std::cout << '\n';
  }
  return 0;
}
