#include <iostream>

using namespace std;

int _max(int a, int b){
  return (a > b) ? a: b;
}
int _min(int a, int b){
  return (a < b) ? a: b;
}

int arr[3][3] = { {-2,-3,3},
                  {-5,-10,1},
                  {10,30,-5}
                }; ;

int minimumPoins(int r, int c){
  int dp[r][c];
  int m = r, n = c;

  dp[m-1][n-1] = arr[m-1][n-1] > 0 ? 1 : abs(arr[m-1][n-1])+1;

  for(int i=m-2; i>=0; i--)
    dp[i][n-1] = max(dp[i+1][n-1] - arr[i][n-1], 1);
  for(int j=n-2; j>=0; j--)
    dp[m-1][j] = max(dp[m-1][j+1] - arr[m-1][j], 1);

  for(int i=m-2; i>=0; i--)
    for(int j=m-2; j>=0; j--){
      int min_points = min(dp[i+1][j], dp[i][j+1]);
      dp[i][j] = max(min_points - arr[i][j], 1);
    }
  return dp[0][0];
}

int main() {
  int ans = minimumPoins(3, 3);
  std::cout << ans << '\n';
  return 0;
}
