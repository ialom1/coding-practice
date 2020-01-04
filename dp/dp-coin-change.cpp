#include <iostream>

using namespace std;

int countChangeWays(int arr[], int m, int n){
  int dp[n+1] = {0};
  dp[0] = 1;
  for(int i=0; i<m; i++){
    int coin = arr[i];
    for(int j=coin; j<=n; j++){
      dp[j] = dp[j] + dp[j-coin];
    }
  }
  return dp[n];
}

int main() {
  int arr[] = {9, 6, 5, 1};
  int m = sizeof(arr)/sizeof(arr[0]);
  int n = 11;
  std::cout << countChangeWays(arr, m, n) << '\n';
  return 0;
}
