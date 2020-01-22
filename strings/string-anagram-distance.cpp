#include <bits/stdc++.h>

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

bool isAnagram(string s, string t) {
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());

  if(s == t) return true;
  return false;
}

int main() {
  string str1, str2;
  getline(cin, str1);
  getline(cin, str2);

  std::cout << countToAnagram(str1, str2) << '\n';
  std::cout << isAnagram(str1, str2) << '\n';
  return 0;
}
