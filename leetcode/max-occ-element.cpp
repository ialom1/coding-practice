#include <iostream>
#include <map>
using namespace std;

int main() {
  int ara[] = {-2,4,6,-5,5,-1,-1,-1};
  int len = sizeof(ara)/sizeof(ara[0]);

  int max = ara[0];
  std::map<int, int> mp;
  for(int i=0; i<len; i++){
    int k = ara[i];
    int c = ++mp[k];
    if(c > mp[max]) max = k;
  }
  std::cout << max << '\n';
  return 0;
}
