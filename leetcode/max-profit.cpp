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

int maxProfitOnce(int ara[], int len){
  int max = 0;
  for(int i=0; i<len-1; i++){
    for(int j=i+1; j<len; j++){
      int profit = ara[j] - ara[i];
      if(profit > max) max = profit;
    }
  }
  return max;
}

int main(){
  int ara[] = {7,1,5,3,6,4};
  int len = sizeof(ara)/sizeof(ara[0]);

  std::cout << "Max Profit selling many times: " << maxProfit(ara, len) << '\n';
  std::cout << "Max profit selling once: " << maxProfitOnce(ara, len) << '\n';
  return 0;
}
