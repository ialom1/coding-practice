#include <iostream>

using namespace std;

#define MAX_NUMS 105
#define MAX_SUM 100005

int max(int a, int b) {
  return (a > b) ? a : b;
}

int dp[MAX_NUMS][MAX_SUM];
int ara[MAX_NUMS];

int root = 50000;
int mini = -1000000;

int dp_func(int pos, int sum) {
  if(pos == 0){
    if(sum == root) return 0;
    return mini;
  }

  if(sum < 0) return mini;
  if(sum > 100000) return mini;
  if(dp[pos][sum] != -1) return dp[pos][sum];

  int ret1 = dp_func(pos-1, sum + ara[pos]) + ara[pos];
  int ret2 = dp_func(pos-1, sum - ara[pos]);
  int ret3 = dp_func(pos-1, sum);
  return dp[pos][sum] = max(ret1, max(ret2, ret3));
}

int main() {
  int n = 5;
  int t[] = {0,1,2,3,4,6};
  for(int i=1; i<=n; i++)
    ara[i] = t[i];
  for(int i=0; i<MAX_NUMS; i++)
    for(int j=0; j<MAX_SUM; j++)
      dp[i][j] = -1;
  int ans = dp_func(n,root);
  cout << ans << endl;
  return 0;
}
