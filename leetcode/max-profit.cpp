#include <iostream>

using namespace std;

int maxProfit(int ara[], int len){
  int total = 0;
  for(int i=0; i<len-1; i++){
    int diff = ara[i+1] - ara[i];
    if(diff > 0) total += diff;
  }
  return total;
}

int main(){
  int ara[] = {7,1,5,3,6,4};
  int len = sizeof(ara)/sizeof(ara[0]);

  std::cout << maxProfit(ara, len) << '\n';
  return 0;
}
