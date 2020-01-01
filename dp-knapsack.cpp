#include <stdio.h>
#include <iostream>

using namespace std;

int max(int a, int b){
  return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n){
  int dp[n+1][W+1];
  for(int i=0; i<=n; i++){
    for(int j=0; j<=W; j++){
      if(i==0 || j==0)
        dp[i][j] = 0;
      else if(wt[i-1] <= j){
        dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
      }
      else
        dp[i][j] = dp[i-1][j];
    }
  }
  return dp[n][W];
}

int main() {
  int val[] = {100, 60, 120};
  int wt[] = {20, 10, 30};
  int  W = 50;
  int n = sizeof(val)/sizeof(val[0]);
  printf("%d", knapSack(W, wt, val, n));
  return 0;
  return 0;
}
