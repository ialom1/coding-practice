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
  int len = 0, row, col;

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if(i == 0 || j == 0)
        dp[i][j] = 0;
      else if(X[i-1] == Y[j-1]){
        dp[i][j] = dp[i-1][j-1] + 1;
        if(len < dp[i][j]){
          len = dp[i][j];
          row = i; col = j;
        }
      }
      else
        dp[i][j] = 0;
    }
  }
  std::cout << "Length of LC Substring: " << len << '\n';

  char arr[len+1];
  int index = len;
  arr[index--] = '\0';
  while (dp[row][col] != 0) {
    arr[index--] = X[row-1];
    row--; col--;
  }
  std::cout << arr << '\n';
}


int main() {
  string X = "OldSite:GeeksforGeeks.org";
  string Y = "NewSite:GeeksQuiz.com";
  lcs(X, Y);
  return 0;
}
