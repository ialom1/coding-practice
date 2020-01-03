#include <stdio.h>
#include <iostream>

using namespace std;

int max(int a, int b){
  return (a > b) ? a : b;
}

void lcs(string X, string Y){
  int m = X.length();
  int n = Y.length();

  int dp[m+1][n+1];

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if(i == 0 || j == 0)
        dp[i][j] = 0;
      else if(X[i-1] == Y[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }

  std::cout << "Length of LC Subsequence: " << dp[m][n] << '\n';

  int index = dp[m][n];
  char str[index+1];
  str[index--] = '\0';
  int i = m, j = n;
  while (i>0 && j>0) {
    if(X[i-1] == Y[j-1]){
      str[index--] = X[i-1];
      i--; j--;
    }
    else if(dp[i-1][j] > dp[i][j-1])
      i--;
    else
      j--;
  }

  std::cout << str << '\n';
}


int main() {
  string X = "AGGTAB";
  string Y = "GXTXAYB";
  lcs(X, Y);
  return 0;
}
