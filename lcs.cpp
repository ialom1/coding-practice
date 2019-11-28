#include <stdio.h>
#include <iostream>

using namespace std;

int max(int a, int b){
  return (a > b) ? a : b;
}

void lcs(string X, string Y){
  int m = X.length();
  int n = Y.length();

  int L[m+1][n+1];

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if(i == 0 || j == 0)
        L[i][j] = 0;
      else if(X[i-1] == Y[j-1])
        L[i][j] = L[i-1][j-1] + 1;
      else
        L[i][j] = max(L[i-1][j], L[i][j-1]);
    }
  }

  int index = L[m][n];
  char str[index+1];
  str[index--] = '\0';
  int i = m, j = n;
  while (i>0 && j>0) {
    if(X[i-1] == Y[j-1]){
      str[index--] = X[i-1];
      i--; j--;
    }
    else if(L[i-1][j] > L[i][j-1])
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
