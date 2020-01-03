#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void expand(string str, int low, int high, vector<string> &set){
  while (low >= 0 && high < str.length()) {
    if(str[low] == str[high]){
      string t = str.substr(low, high-low+1);
      set.push_back(t);
      // std::cout << t << '\n';
    }
    ++high, --low;
  }
}

void allPallindromes(string str, vector<string> &set){
  for (int i = 0; i < str.length(); i++) {
    expand(str, i, i, set);
    expand(str, i, i+1, set);
  }
}

int freq(string str, char c){
  int count = 0;
  for (int i = 0; i < str.length(); i++) {
    if(str[i] == c) ++count;
  }
  return count;
}

int main() {
  std::string str = "abcbs";
  std::vector<string> set;
  allPallindromes(str, set);
  sort(set.begin(), set.end());
  for(auto i: set){
    std::cout << i << ' ';
  }
  return 0;
}
