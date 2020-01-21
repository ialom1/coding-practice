#include <iostream>

using namespace std;

void _print(int arr[], int len){
  for(int i=0; i<len; i++)
    std::cout << arr[i] << ' ';
  std::cout << '\n';
}

int main() {
  int ara[] = {0,0,1};
  int len = sizeof(ara)/sizeof(ara[0]);

  std::cout << "Initial array: " << '\n';
  _print(ara, len);

  int z = 0, i=0, j=0, ans[len] = {0};
  for(i=0; i<len; i++){
    if(ara[i] == 0){
      ++z;
    } else {
      ans[j++] = ara[i];
    }
  }

  std::cout << "Reordered array: " << '\n';
  _print(ans, len);
  return 0;
}
