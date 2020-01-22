#include <iostream>

using namespace std;

int _find(char c){
  if(c == 'I') return 1;
  if(c == 'V') return 5;
  if(c == 'X') return 10;
  if(c == 'L') return 50;
  if(c == 'C') return 100;
  if(c == 'D') return 500;
  if(c == 'M') return 1000;
}
int convert(string str){
  int res = 0;
  int len = str.length();
  for(int i=0; i<len; i++){
    if(i < len-1 && _find(str[i])  < _find(str[i+1])){
      res -= _find(str[i]);
    }
    else{
      res += _find(str[i]);
    }
  }
  return res;
}

int main() {
  std::cout << convert("III") << '\n';
  return 0;
}
