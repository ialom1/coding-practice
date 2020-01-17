#include <iostream>

using namespace std;

void _print(char arr[], int len){
  for(int i=0; i<len; i++)
  std::cout << arr[i] << ' ';
  std::cout << '\n';
}

void swap(char &a, char &b) {
  char t = a;
  a = b;
  b = t;
}

void _reverse(char str[], int len){
  for(int i=0; i<len/2; i++) {
    swap(str[i], str[len-1-i]);
  }
}

int main() {
  char input[] = {'h', 'e', 'l', 'l', 'o'};
  int len = sizeof(input)/sizeof(input[0]);
  _reverse(input, len);
  _print(input, len);
  return 0;
}
