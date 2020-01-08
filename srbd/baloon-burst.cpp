#include <iostream>

using namespace std;

int max(int a, int b){
  return (a>b) ? a :  b;
}

int coins[] = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1};
int maxCoins(int n){
  int dp[n+1][n+1] = {0};
  for(int k=2; k<n; k++){
    for(int left=0; left<n-k; left++){
      int right = left+k;
      for(int i=left+1; i<right; i++){
        dp[left][right] = max(
                            dp[left][right],
                            coins[left]*coins[i]*coins[right]
                            + dp[left][i] + dp[i][right]
                          );
      }
    }
  }
  return dp[0][n-1];
}

int main() {
  int len = sizeof(coins)/sizeof(coins[0]);
  std::cout << maxCoins(len) << '\n';
  return 0;
}
