#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

string commpress(string str){
  int count = 0;
  int len = str.length();
  string res;

  for (int i = 0; i < len; i++) {
    ++count;
    if(str[i] != str[i+1] && i < (len-1)){
      res += str[i];
      res += to_string(count);
      count = 0;
    }
  }
  if(len < res.length()) return str;
  return res;
}

int main(){
  string str = "abbcccde";
  std::cout << commpress(str) << '\n';
  return 0;
}
