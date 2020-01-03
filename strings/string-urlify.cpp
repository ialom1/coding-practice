#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace  std;

// Code to Remove all spaces
// while (str[i]) {
//   if(str[i] != ' ')
//     str[j++] = str[i];
//   i++;
// }
// str[j] = '\0';

string urlify(string str){
  int len = str.length(), pos = 0;
  int start = 0, end = len-1;
  string res;
  while (start < len) {
    if(str[start] != ' ') break;
    ++start;
  }
  while (end > 0) {
    if(str[end] != ' ') break;
    --end;
  }
  for (int i = start; i <= end; i++) {
    if(str[i] == ' ') res += "%20";
    else res += str[i];
  }
  std::cout << start << " " << end << '\n';
  return res;
}

int main() {
  string str = " abc def   ";
  std::cout << urlify(str) << '\n';
}
