#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace  std;

string sortString(string str){
  string res = str;
  sort(res.begin(), res.end());
  return res;
}

int isPermutation(string str, string perm){
  if(str.length() != perm.length()) return 0;
  return sortString(str) == sortString(perm);
}

int main() {
  string str1 = "bca";
  string str2 = "abd";
  string str = "abc";

  std::cout << isPermutation(str, str1) << '\n';
  std::cout << isPermutation(str, str2) << '\n';
}
