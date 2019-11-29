#include<iostream>
#include<stdio.h>
#include <cstdlib>

using namespace std;

int countToAnagram(string str1, string str2){
  int arr[26] = {0};
  for (int i = 0; i < str1.length(); i++)
    ++arr[str1[i] - 'a'];
  for (int i = 0; i < str2.length(); i++)
    --arr[str2[i] - 'a'];

  int sum = 0;
  for (int i = 0; i < 26; i++) {
    sum += abs(arr[i]);
  }
  return sum;
}

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    std::cout << countToAnagram(str1, str2) << '\n';
    return 0;
}
