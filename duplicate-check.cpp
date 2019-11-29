#include <stdio.h>
#include <iostream>

using namespace  std;

int isDuplicate(string str){
  int arr[128] = {0};
  if(str.length() > 128) return 0;
  for (int i = 0; i < str.length(); i++) {
    int c = str.at(i);
    // std::cout << c << arr[c] << '\n';
    if(arr[c] == 1) return 1;
    arr[c] = 1;
  }
  return 0;
}

int main() {
  string str1 = "abcdefghi";
  string str2 = "abccefghi";

  std::cout << isDuplicate(str1) << '\n';
  std::cout << isDuplicate(str2) << '\n';
}
