#include <stdio.h>
#include <iostream>

using namespace std;

int min(int a, int b, int c){
  if(a < b && a < c) return a;
  else if(b < a && b < c) return b;
  else return c;
}

int lcs(string X, string Y){
  int m = X.length();
  int n = Y.length();

  int dp[m+1][n+1];

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if(i == 0)
        dp[i][j] = j;
      else if(j == 0)
        dp[i][j] = i;

      else if(X[i-1] == Y[j-1])
        dp[i][j] = dp[i-1][j-1];
      else
        dp[i][j] = 1 + min(dp[i-1][j],
                           dp[i][j-1],
                           dp[i-1][j-1]
                         );
    }
  }

  return dp[m][n];
}


int main() {
  string X = "tabriz";
  string Y = "torino";
  cout << lcs(X, Y) << endl;
  return 0;
}
