#include <iostream>

using namespace std;

int min(int a, int b){
  return (a < b) ? a : b;
}

//Unique ways to make amount of n
int uniqueWays(int arr[], int k, int n){
  int dp[n+1] = {0};
  dp[0] = 1;
  for(int i=0; i<k; i++){
    int coin = arr[i];
    for(int j=coin; j<=n; j++){
      dp[j] += dp[j-coin];
    }
  }
  return dp[n];
}

//All possible of ways to make amount of n
int totalWays(int arr[], int k, int n){
  int dp[n+1] = {0};
  dp[0] = 1;
  for(int i=1; i<=n; i++){
    for(int j=0; j<k; j++){
      int coin = arr[j];
      if(coin <= i){
        dp[i] += dp[i-coin];
      }
    }
  }
  return dp[n];
}

//  using each coin once
// int useOnce(int arr[], int k, int n){
//   int dp[n+1] = {0};
//   dp[0] = 1;
//   for(int i=1; i<=n; i++){
//     for(int j=0; j<k; j++){
//       int coin = arr[j];
//       if(coin <= i && dp[i-coin]){
//         dp[i] = 1;
//       }
//     }
//   }
//   return dp[n];
// }

//Minimum coins to make amount of n
int minCoins(int arr[], int k, int n){
  int dp[n+1];
  for(int i=0; i<n+1; i++)
    dp[i] = n+1;
  dp[0] = 0;
  for(int i=1; i<=n; i++){
    for(int j=0; j<k; j++){
      int coin = arr[j];
      if(coin <= i){
        dp[i] = min(dp[i], dp[i-coin]+1);
      }
    }
  }
  return (dp[n] > n) ? -1 : dp[n];
}

int main() {
  int arr[] = {1, 2};
  int m = sizeof(arr)/sizeof(arr[0]);
  int n = 4;
  std::cout << "Total ways: " << totalWays(arr, m, n) << '\n';    // 5 ways total
  std::cout << "Unique ways: " << uniqueWays(arr, m, n) << '\n';  // 3 ways unique
  std::cout << "Minimum coins: " << minCoins(arr, m, n) << '\n';  // 2 coins needed min
  // std::cout << "Using once: " << useOnce(arr, m, n) << '\n';
  return 0;
}
